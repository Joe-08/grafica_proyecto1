#ifndef CAMARA_H
#define CAMARA_H

#include "CImg.h"
#include "vec3.h"
#include "Rayo.h"
#include "Objeto.h"
#include "Luz.h"
#include <vector>
#include <fstream>
using namespace std;
using namespace cimg_library;
typedef unsigned char BYTE;

float clamp(float lo, float hi, float v) {
    return std::max(lo, std::min(hi, v));
}

class Camara {
public:
    float fov,f,a,b;
    float w,h;
    int prof_max;
    vec3 eye, center, up;
    vec3 xe,ye,ze;
    CImg<BYTE> *pImg;
    
    Camara(){ prof_max = 4; };
    void init(float angulo, float ne, int ancho, int alto, vec3 pos, vec3 cen, vec3 _up) {
        fov = angulo;
        eye = pos;
        center = cen;
        up = _up;
        f = ne;
        w = ancho;
        h = alto;

        a = 2*f*tan(fov*3.14159265/360);//2f*tan(fov/2)
        b = a*w/h;
    }
    void calcular_vectores() {
        ze = eye-center;
        ze.normalize();
        xe = up.prod_cruz(ze);
        xe.normalize();
        ye = ze.prod_cruz(xe);
        ye.normalize();//puede que se quite
    }
    void Renderizar(Luz luz, std::vector<Objeto*> &vec_objetos) {
        pImg = new CImg<BYTE>(w,h,1,10);
        CImgDisplay dis_img((*pImg),"Imagen");

        Rayo rayo;
        rayo.origen = eye;
        float t,t_min;
        vec3 color;
        vec3 normal,normal_min;

        for(int y=0;y<h;y++) {
            for(int x=0;x<w;x++) {
                rayo.direccion = ze*(-f) + ye*a*(y/h-0.5) + xe*b*(x/w-0.5); //Rayo en coordenadas de la camara
                rayo.direccion.normalize();
                bool intersecta = calcular_color(rayo,luz,vec_objetos,color,0);
                
                (*pImg)(x,h-1-y,0) = (BYTE)(color.x*255);
                (*pImg)(x,h-1-y,1) = (BYTE)(color.y*255);
                (*pImg)(x,h-1-y,2) = (BYTE)(color.z*255);
            }
        }
        dis_img.render((*pImg));
        dis_img.paint();

        while(!dis_img.is_closed()) {
            dis_img.wait();
        }
    }

    bool calcular_color(Rayo rayo,Luz &luz,std::vector<Objeto*> &vec_objetos,vec3 &color,int prof) {
        if(prof >= prof_max) {
            color = vec3(0,0,0);
            return false;
        }
        
        float t_calculado,t=1e6;
        vec3 color_min(0,0,0);
        vec3 normal, N;
        bool intersecta = false;
        Objeto *pObj;

        for(auto pObjTmp: vec_objetos) {
            if(pObjTmp->interseccion(rayo,t_calculado,normal)) {
                if(t_calculado < t) {
                    intersecta = true;
                    t = t_calculado;
                    N = normal;
                    pObj = pObjTmp;
                }
            }
        }
        if(intersecta) {
            vec3 luz_ambiente = luz.color*0.3; //Calcular luz ambiente  
            color_min = pObj->color;
            //pi punto de interseccion
            vec3 pi = rayo.origen+rayo.direccion*t;
            //L vector hacia la luz
            vec3 L = luz.pos-pi;
            L.normalize();

            //Calculando la sombra
            Rayo rayo_sombra;
            rayo_sombra.direccion = L;
            rayo_sombra.origen = pi+L*0.1;
            vec3 color_tmp;
            bool intersec = calcular_color(rayo_sombra,luz,vec_objetos,color_tmp,prof+1);
            if(!intersec) {
                float factor_difuso = L.prod_punto(N); // N*L
                vec3 luz_difusa(0,0,0);
                if(factor_difuso>0) {
                    luz_difusa = luz.color*factor_difuso*pObj->kd;
                }
                //iluminacion especular
                vec3 r = N*N.prod_punto(L)*2-L;
                vec3 v = -rayo.direccion;
                r.normalize();
                vec3 luz_especular(0,0,0);
                if(pObj->ke>0) {
                    float factor_especular = pow(r.prod_punto(v),pObj->n);
                    if(factor_especular>0) {
                        luz_especular = luz.color*factor_especular*pObj->ke;
                    }
                }
                color_min = color_min*(luz_ambiente+luz_difusa+luz_especular);
            } else {
                color_min = color_min*luz_ambiente;
            }
            //Rayos refractados
            vec3 color_refractado;
            float kr = pObj->kr;
            bool afuera = rayo.direccion.prod_punto(N)<0;
            vec3 bias = 0.001*N;
            if(pObj->ior > 0) {
                fresnel(rayo.direccion,N,pObj->ior,kr);
                if(kr<1) {
                    vec3 refDir = refract(rayo.direccion,N,pObj->ior);
                    refDir.normalize();
                    vec3 refOri = afuera?pi-bias:pi+bias;
                    Rayo rayo_refractado(refOri,refDir);
                    calcular_color(rayo_refractado,luz,vec_objetos,color_refractado,prof+1);
                }
            }
            //Rayos reflectados
            vec3 color_reflejado;
            if(kr > 0) {
                Rayo rayo_ref;
                vec3 vec_rayo = -rayo.direccion;

                vec3 R = N*(vec_rayo.prod_punto(N))*2-vec_rayo;
                R.normalize();
                rayo_ref.direccion = R;
                rayo_ref.origen = afuera?pi+bias:pi-bias;
                
                //lanzar rayo secundario
                bool intersect = calcular_color(rayo_ref,luz,vec_objetos,color_reflejado,prof+1);
                //calcular intersecciones
                if(intersect) color_reflejado = vec3(0);//color_min = color_min+color_reflejado*0.8;
            }
            color_min = color_min+color_reflejado*kr+color_refractado*(1-kr);
            color_min.max_to_one();
            color = color_min;
            return true;
        }
        color = color_min;
        return false;
    }
    vec3 refract(vec3 I,vec3 N,float ior) {
        float cosi = clamp(-1,1,I.prod_punto(N));
        float etai = 1, etat = ior;
        vec3 n = N;
        if(cosi<0) { cosi = -cosi; } else { std::swap(etai,etat); n= -N; }
        float eta = etai/etat;
        float k = 1-eta*eta*(1-cosi*cosi);
        return k < 0 ? 0 : eta * I + (eta * cosi - sqrtf(k)) * n;
    }
    void fresnel(vec3 I,vec3 N,float ior,float &kr){
        float cosi = clamp(-1,1,I.prod_punto(N));
        float etai = 1, etat = ior;
        if(cosi>0) std::swap(etai,etat);
        float sint = etai/etat*sqrtf(std::max(0.f,1-cosi*cosi));
        if(sint>=1) kr = 1;
        else {
            float cost = sqrtf(std::max(0.f,1-sint*sint));
            cosi = fabsf(cosi);
            float Rs = ((etat*cosi)-(etai*cost))/((etat*cosi)+(etai*cost));
            float Rp = ((etai*cosi)-(etat*cost))/((etai*cosi)+(etat*cost));
            kr = (Rs*Rs+Rp*Rp)/2;
        }
    }
    ~Camara(){};
};

#endif