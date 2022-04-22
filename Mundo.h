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
    void escenario_proyecto(){
    cam.init(60,10, 624, 352,
             vec3(0,19,30),
             vec3(0,10,0),
             vec3(0,1,0));
        cam.calcular_vectores();

        luz.set(vec3(0,10,0), vec3(1,1,1),0.8);
      
      Cilindro *cil1 = new Cilindro();
      cil1->color = vec3(1,1,1);
      cil1->pa = vec3(0,20,0);
      cil1->pb = vec3(0,0,0);
      cil1->radio = 10;
      cil1->kr = 0;
      cil1->ior = 1.5;
      cil1->type = kReflexionyRefraccion;
      vec_objetos.emplace_back(cil1);

      Cilindro *cil2 = new Cilindro();
      cil2->color = vec3(1,1,0);
      cil2->pa = vec3(0,20,0);
      cil2->pb = vec3(0,22,0);
      cil2->radio = 11;
      cil2->kd = 1;
      vec_objetos.emplace_back(cil2);

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
        esf1->color = vec3(1,1,1);
        esf1->kr = 0;
        esf1->ior = 1.5;
        esf1->type = kReflexionyRefraccion;
        vec_objetos.emplace_back(esf1);

        Esfera *esf2 = new Esfera();
        esf2->centro = vec3(-5,5,0);
        esf2->radio = 1;
        esf2->color = vec3(1,1,1);
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