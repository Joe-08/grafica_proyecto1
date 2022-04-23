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
      luz1->set(vec3(-70,70,70), vec3(0.5,0.5,0.5),0.1);
      luces.push_back(luz1);

      Luz *luz2 = new Luz();
      luz2->set(vec3(0,10,0.75), vec3(0.5,0.5,0.5),0.1);
      luces.push_back(luz2);
        //luz.set(vec3(0,10,0), vec3(1,1,1),0.5);
        
      Cilindro *jarron_vidrio = new Cilindro();
      jarron_vidrio->color = vec3(0.1,0.1,0.1);
      jarron_vidrio->pa = vec3(0,20,0);
      jarron_vidrio->pb = vec3(0,0,0);
      jarron_vidrio->radio = 10;
      jarron_vidrio->kr = 0.9;
      jarron_vidrio->ior = 1.5;
      jarron_vidrio->type = kReflexionyRefraccion;
      vec_objetos.emplace_back(jarron_vidrio);

      Cilindro *jarron_tapa = new Cilindro();
      jarron_tapa->color = vec3(0.75,0.75,0.25);
      jarron_tapa->pa = vec3(0,20,0);
      jarron_tapa->pb = vec3(0,22,0);
      jarron_tapa->radio = 11;
      jarron_tapa->kd = 1;
      vec_objetos.emplace_back(jarron_tapa);
      
      Cilindro *jarron_vacio = new Cilindro();
      jarron_vacio->color = vec3(0,0,0);
      jarron_vacio->pa = vec3(0,20,0);
      jarron_vacio->pb = vec3(0,22,0);
      jarron_vacio->radio = 9;
      jarron_vacio->kr = 0;
      jarron_vacio->ior = 1;
      jarron_vacio->type = kReflexionyRefraccion;
      vec_objetos.emplace_back(jarron_vacio);

      Esfera *esf1 = new Esfera();
      esf1->centro = vec3(0,10,0);
      esf1->radio = 0.5;
      esf1->color = vec3(1,1,1);
      vec_objetos.emplace_back(esf1);
      
      Esfera *esf1_glow = new Esfera();
      esf1_glow->centro = vec3(0,10,0);
      esf1_glow->radio = 1;
      esf1_glow->color = vec3(1,1,0.75);
      esf1_glow->kr = 0.9;
      esf1_glow->ior = 1.5;
      esf1_glow->type=kReflexionyRefraccion;
      vec_objetos.emplace_back(esf1_glow);

      Esfera *esf2 = new Esfera();
      esf2->centro = vec3(-5,5,0);
      esf2->radio = 1;
      esf2->color = vec3(1,1,1);
      esf2->kd = 1;
      esf2->n = 8;
      vec_objetos.emplace_back(esf2);
      
      Cubo *cubo1 = new Cubo();
      cubo1->color = vec3(1,0,0);
      cubo1->centro = vec3(-20,10,5);
      cubo1->size = vec3(5,5,5);
      cubo1->kd = 1;
      cubo1->ke= 0.5;
      cubo1->n = 8;
      vec_objetos.emplace_back(cubo1);
      
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