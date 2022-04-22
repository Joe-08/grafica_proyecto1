#ifndef OBJETO_H
#define OBJETO_H

#include "vec3.h"
#include "Rayo.h"

template <typename T>
int sign (const T &val) { return (val > T(0)) - (val < T(0)); }

enum MaterialType { kDifuso, kReflexion, kReflexionyRefraccion};

class Objeto {
public:
    vec3 color;
    MaterialType type;
    float kd,ke,kr,n,ior;
    Objeto(){ type=kDifuso; kd=1; ke=0; kr=0; n=1; ior=1; };
    virtual bool interseccion(Rayo &rayo, float &t, vec3 &normal) = 0;
    virtual ~Objeto(){};
};

class Esfera : public Objeto {
public:
    vec3 centro;
    float radio;
    Esfera(){};
    bool interseccion(Rayo &rayo, float &t, vec3 &normal) {
        vec3 d = rayo.direccion;
        vec3 o = rayo.origen;
        vec3 oc = o-centro;
        float a = d.prod_punto(d);
        float b = 2*d.prod_punto(oc);
        float c = oc.prod_punto(oc)-radio*radio;

        float determinante = b*b - 4*a*c;
        if(determinante > 0) {
            float t1 = (-b - sqrt(determinante))/(2*a);
            float t2 = (-b + sqrt(determinante))/(2*a);
            t = std::min(t1, t2);
            if (t<=0) {return false;}
            vec3 pi = o+d*t;
            normal = pi-centro;
            normal.normalize();
            return true;
        }
        return false;
    }
    ~Esfera(){};
};

class Plano : public Objeto {
public:
    vec3 normal;
    float distancia;
    Plano(){};
    bool interseccion(Rayo &rayo, float &t, vec3 &_normal) {
        t = - (normal.prod_punto(rayo.origen) + distancia) / (normal.prod_punto(rayo.direccion));
        if (t < 0) {
            return false;
        }
        // falta corregir la normal segun la direccion del rayo
        _normal = normal;
        return true;
    }
    ~Plano(){};
};

class Cilindro : public Objeto {
public:
    vec3 pa,pb;
    float radio;
    Cilindro(){};
    bool interseccion(Rayo &rayo, float &t, vec3 &normal) {
        vec3 rd = rayo.direccion;
        vec3 ro = rayo.origen;
        vec3 ca = pb-pa;
        vec3 oc = ro-pa;
        float caca= ca.prod_punto(ca);
        float card = ca.prod_punto(rd);
        float caoc = ca.prod_punto(oc);
        float a = caca - card*card;
        float b = caca*oc.prod_punto(rd) - caoc*card;
        float c = caca*oc.prod_punto(oc) - caoc*caoc - radio*radio*caca;
        float h = b*b - a*c;
        if(h<0.0) {return false;}
        h = sqrt(h);
        t = (-b - h)/a;
        if(t<=0) return false;
        float y = caoc+t*card;
        if(y>0.0 && y<caca) {
            normal = (oc+rd*t-ca*y/caca)/radio;
            normal.normalize();
            return true;
        }//(oc+t*rd-ca*y/caca)/ra
        t = (((y<0.0)?0.0:caca)-caoc)/card;
        if(t<=0) return false;
        if(abs(b+a*t)<h) {
            normal = ca*sign(y)/caca;
            normal.normalize();
            return true;
        }//ca*sign(y)/caca
        return false;
    }
    ~Cilindro(){};
};

#endif