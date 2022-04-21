#ifndef MUNDO_H
#define MUNDO_H

#include "Camara.h"
#include "Objeto.h"//vector<Objeto*> objetos;
#include "Luz.h"
#include <vector>

class Mundo {
public:
    Camara cam;
    Luz luz;
    std::vector<Objeto*> vec_objetos;

    Mundo(){};
    void Renderizar();
    void escenario1() {
        cam.init(60,10, 1280, 720,
             vec3(20,40, 80),
             vec3(0,0,0),
             vec3(0,1,0));
        cam.calcular_vectores();

        luz.set(vec3(-10,50,50), vec3(1,1,1));
    
        Esfera *esf2 = new Esfera;
        esf2->centro = vec3(10,20,40);
        esf2->radio = 15;
        esf2->color = vec3(0,1,0);
        esf2->kd = 0.8;
        esf2->ke = 0.5;
        esf2->ior = 0.9;
        vec_objetos.emplace_back(esf2);

        Esfera *esf3 = new Esfera;
        esf3->centro = vec3(0,20,0);
        esf3->radio = 20;
        esf3->color = vec3(1,0,1);
        esf3->kd = 0.8;
        esf3->n = 8;
        vec_objetos.emplace_back(esf3);

        Esfera *esf4 = new Esfera;
        esf4->centro = vec3(25,20,30);
        esf4->radio = 5;
        esf4->color = vec3(1,0,0);
        esf4->kd = 0.5;
        esf4->ke = 0.8;
        esf4->n = 8;
        vec_objetos.emplace_back(esf4);

        Plano *plano = new Plano;
        plano->normal = vec3(0,10,0);
        plano->normal.normalize();
        plano->distancia = 0;
        plano->color = vec3(0,0.5,0.5);
        plano->kd = 1.5;
        plano->ke = 0;
        vec_objetos.emplace_back(plano);

        cam.Renderizar(luz,vec_objetos);
    }
    void escenario3() {
        cam.init(60,10, 600, 400,
                 vec3(20,60, 80),
                 vec3(0,0,0),
                 vec3(0,1,0));
        cam.calcular_vectores();

        luz.set(vec3(0,80,0), vec3(1,1,1));
        Esfera *e1 = new Esfera();
        e1->centro = vec3(0,30,0);
        e1->radio = 20;
        e1->color = vec3(1,0,0);
        e1->kd = 0.8;
        e1->ke = 0.4;
        vec_objetos.emplace_back(e1);

        Esfera *e2 = new Esfera();
        e2->centro = vec3(20,30,40);
        e2->radio = 10;
        e2->color = vec3(1,1,0);
        e2->kd = 0.8;
        e2->ke = 0.8;
        e2->ior = 0.9;
        vec_objetos.emplace_back(e2);

        Esfera *e3 = new Esfera();
        e3->centro = vec3(-15,30,40);
        e3->radio = 20;
        e3->color = vec3(0,1,0);
        e3->kd = 0.8;
        e3->ke = 0.8;
        e3->ior = 0.9;
        vec_objetos.emplace_back(e3);

        Plano *plano = new Plano;
        plano->normal = vec3(0,50,0);
        plano->normal.normalize();
        plano->distancia = 0.8;
        plano->color = vec3(0.5,0.5,0.9);
        plano->kd = 0.9;
        plano->ke = 0;
        vec_objetos.emplace_back(plano);

        cam.Renderizar(luz,vec_objetos);
    }
    void escenario2() {
        cam.init(60, 10, 600, 400,
                vec3(20, 40, 120),
                vec3(0, 0, 0),
                vec3(0, 1, 0));
        cam.calcular_vectores();

        luz.set(vec3(35, 35, 50), vec3(1, 1, 1));
        float pos = 20;
        for (int f = -5; f < 5; f++) {
            for (int c = -5; c < 5; c++) {
                Esfera *esf1 = new Esfera();
                esf1->centro = vec3(f*pos, 0, c*pos);
                esf1->radio = 7;
                esf1->color = vec3(1, 0, 0);
                esf1->kd = 0.8;
                esf1->ke = 0.9;
                esf1->kr = 0.8;
                //esf1->ior = 1.5;
                esf1->n = 8;
                vec_objetos.emplace_back(esf1);
            }
        }
        Plano *plano = new Plano();
        plano->normal = vec3(0,50,1);
        plano->normal.normalize();
        plano->distancia = 0.8;
        plano->color = vec3(0.5,0.5,0);
        plano->kd = 0.9;
        plano->ke = 0;
        vec_objetos.emplace_back(plano);

        cam.Renderizar( luz, vec_objetos );
    }

    void escenario_proyecto(){
    cam.init(60,10, 1280, 720,
             vec3(0,19,30),
             vec3(0,10,0),
             vec3(0,1,0));
        cam.calcular_vectores();

        luz.set(vec3(0,10,50), vec3(1,1,1));
      
      Cilindro *cil1 = new Cilindro();
      cil1->color = vec3(1,1,1);
      cil1->pa = vec3(0,20,0);
      cil1->pb = vec3(0,0,0);
      cil1->radio = 10;
      cil1->kr = 0.5;
      cil1->ior = 1.5;
      vec_objetos.emplace_back(cil1);
/*
      Cilindro *cil2 = new Cilindro();
      cil2->color = vec3(1,1,1);
      cil2->pa = vec3(0,20,0);
      cil2->pb = vec3(0,0,0);
      cil2->radio = 9.5;
      cil2->kr = 1;
      cil2->ior = 1;
      vec_objetos.emplace_back(cil2);
*/

        Esfera *esf1 = new Esfera();
        esf1->centro = vec3(0,10,0);
        esf1->radio = 1;
        esf1->color = vec3(1,1,0);
        esf1->kd = 1;
        esf1->n = 8;
        vec_objetos.emplace_back(esf1);

        Esfera *esf2 = new Esfera();
        esf2->centro = vec3(-5,5,0);
        esf2->radio = 1;
        esf2->color = vec3(1,1,0);
        esf2->kd = 1;
        esf2->n = 8;
        vec_objetos.emplace_back(esf2);

      Plano *plano = new Plano();
        plano->normal = vec3(0,1,0);
        plano->normal.normalize();
        plano->distancia = 0;
        plano->color = vec3(0,0.5,0.5);
        plano->kd = 1.5;
        vec_objetos.emplace_back(plano);
        

      cam.Renderizar( luz, vec_objetos );

    }
    ~Mundo(){};
};

#endif