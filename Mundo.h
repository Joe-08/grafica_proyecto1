#ifndef MUNDO_H
#define MUNDO_H

#include "Camara.h"
#include "Objeto.h"//vector<Objeto*> objetos;
#include "Luz.h"
#include <vector>

class Mundo {
public:
    Camara cam;
    std::vector<Luz*> luces;
    std::vector<Objeto*> vec_objetos;

    Mundo(){};
    void escenario_proyecto(){
    cam.init(60,10, 624, 352,
             vec3(0,19,30),
             vec3(0,10,0),
             vec3(0,1,0));
        cam.calcular_vectores();
      Luz *luz1 = new Luz();
      luz1->set(vec3(-70,70,70), vec3(1,1,1),0.1);
      luces.push_back(luz1);

      Luz *luz2 = new Luz();
      luz2->set(vec3(0,10,0), vec3(0.1,0.1,0),0.5);
      luces.push_back(luz2);
        //luz.set(vec3(0,10,0), vec3(1,1,1),0.5);
        
      Cilindro *cil1 = new Cilindro();
      cil1->color = vec3(0,0,0);
      cil1->pa = vec3(0,20,0);
      cil1->pb = vec3(0,0,0);
      cil1->radio = 10;
      cil1->kr = 0.9;
      cil1->ior = 1.5;
      cil1->type = kReflexionyRefraccion;
      vec_objetos.emplace_back(cil1);

      Cilindro *cil2 = new Cilindro();
      cil2->color = vec3(0.5,0.5,0);
      cil2->pa = vec3(0,20,0);
      cil2->pb = vec3(0,22,0);
      cil2->radio = 11;
      cil2->kd = 1;
      vec_objetos.emplace_back(cil2);
      
      Cilindro *cil3 = new Cilindro();
      cil3->color = vec3(0,0,0);
      cil3->pa = vec3(0,20,0);
      cil3->pb = vec3(0,22,0);
      cil3->radio = 9;
      cil3->kr = 0;
      cil3->ior = 1;
      cil3->type = kReflexionyRefraccion;
      vec_objetos.emplace_back(cil3);


      Cilindro *cil4 = new Cilindro();
      cil4->color = vec3(1,1,1);
      cil4->pa = vec3(-20,20,20);
      cil4->pb = vec3(-20,20,0);
      cil4->radio = 10;
      vec_objetos.emplace_back(cil4);


        Esfera *esf1 = new Esfera();
        esf1->centro = vec3(0,10,0);
        esf1->radio = 1;
        esf1->color = vec3(1,1,1);
        esf1->kd = 1;
        esf1->n = 8;
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
        

      cam.Renderizar( luces, vec_objetos );

    }
    ~Mundo(){};
};

#endif