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

      Luz *luz1 = new Luz();
      luz1->set(vec3(70,70,70), vec3(1,1,1),0.7);
      luces.push_back(luz1);
      Luz *luz2 = new Luz();
      luz2->set(vec3(0,10,0.75), vec3(0.9,1,0.9),0.7);
      luces.push_back(luz2);
        //luz.set(vec3(0,10,0), vec3(1,1,1),0.5);
       
      // --------- JARRON -------------
      Cilindro *jarron_vidrio = new Cilindro();
      jarron_vidrio->color = vec3(0.1,0.1,0.1);
      jarron_vidrio->pa = vec3(0,20,0);
      jarron_vidrio->pb = vec3(0,0,0);
      jarron_vidrio->radio = 10;
      jarron_vidrio->kr = 0.5;
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

      // ------- LUCIERNAGAS ---------
      Esfera *luci1 = new Esfera();
      luci1->centro = vec3(0,10,0);
      luci1->radio = 0.5;
      luci1->color = vec3(1,1,1);
      vec_objetos.emplace_back(luci1);
      
      Esfera *luci1_glow = new Esfera();
      luci1_glow->centro = vec3(0,10,0);
      luci1_glow->radio = 1;
      luci1_glow->color = vec3(1,1,0.75);
      luci1_glow->kr = 0.9;
      luci1_glow->ior = 1.2;
      luci1_glow->type=kReflexionyRefraccion;
      vec_objetos.emplace_back(luci1_glow);

      Esfera *luci2 = new Esfera();
      luci2->centro = vec3(-5,5,0);
      luci2->radio = 1;
      luci2->color = vec3(1,1,1);
      luci2->kd = 1;
      luci2->n = 8;
      vec_objetos.emplace_back(luci2);
      

      // --------- OBJETOS EXTRA -----------
      Cubo *cubo1 = new Cubo();
      cubo1->color = vec3(1,0,0);
      cubo1->centro = vec3(-30,5,5);
      cubo1->size = vec3(5,5,5);
      cubo1->kd = 1;
      cubo1->ke = 0.5;
      cubo1->n = 8;
      vec_objetos.emplace_back(cubo1);

      Cubo *cubo2 = new Cubo();
      cubo2->color = vec3(1,1,0);
      cubo2->centro = vec3(0,10,-30);
      cubo2->size = vec3(2,10,2);
      cubo2->kd = 1;
      cubo2->ke = 0.5;
      cubo2->n = 8;
      vec_objetos.emplace_back(cubo2);

      Cilindro *cilindro1 = new Cilindro();
      cilindro1->color = vec3(0,0,0);
      cilindro1->pa = vec3(-10,5,30);
      cilindro1->pb = vec3(10,5,30);
      cilindro1->radio = 5;
      cilindro1->type = kReflexion;
      cilindro1->kr = 0.8;
      cilindro1->ior = 1.2;
      vec_objetos.emplace_back(cilindro1);

      Esfera *piramide1 = new Esfera();
      piramide1->color = vec3(0,1,0);
      piramide1->centro = vec3(20,5,10);
      piramide1->radio = 5;
      piramide1->kd = 1;
      piramide1->ke= 0.5;
      piramide1->n = 8;
      vec_objetos.emplace_back(piramide1);

      Esfera *piramide2 = new Esfera();
      piramide2->color = vec3(1,0,0);
      piramide2->centro = vec3(20,5,0);
      piramide2->radio = 5;
      piramide2->kd = 1;
      piramide2->ke= 0.5;
      piramide2->n = 8;
      vec_objetos.emplace_back(piramide2);

      Esfera *piramide3 = new Esfera();
      piramide3->color = vec3(1,0,0);
      piramide3->centro = vec3(30,5,10);
      piramide3->radio = 5;
      piramide3->kd = 1;
      piramide3->ke= 0.5;
      piramide3->n = 8;
      vec_objetos.emplace_back(piramide3);

      Esfera *piramide4 = new Esfera();
      piramide4->color = vec3(0,1,0);
      piramide4->centro = vec3(30,5,0);
      piramide4->radio = 5;
      piramide4->kd = 1;
      piramide4->ke= 0.5;
      piramide4->n = 8;
      vec_objetos.emplace_back(piramide4);

      Esfera *piramide5 = new Esfera();
      piramide5->color = vec3(0,0,1);
      piramide5->centro = vec3(25,10,5);
      piramide5->radio = 5;
      piramide5->kd = 1;
      piramide5->ke= 0.5;
      piramide5->n = 8;
      vec_objetos.emplace_back(piramide5);


      // ---------- PISO -------------      
      Plano *plano = new Plano();
      plano->normal = vec3(0,1,0);
      plano->normal.normalize();
      plano->distancia = 0;
      plano->color = vec3(0,0.5,0.5);
      plano->kd = 1.5;
      vec_objetos.emplace_back(plano);

      // ------- RENDERIZACIÓN ---------
      for(int i = 0; i <= 360; i+=60){
        cam.eye = vec3(cos(i*M_PI/180)*30,19,sin(i*M_PI/180)*30);
        cam.calcular_vectores();
        cam.Renderizar( luces, vec_objetos, i);
      }

      //ffmpeg -r 60 -f image2 -s 624x352 -i fotograma%d.bmp -vcodec libx264 -crf 25 output.mp4
      //ffmpeg -i output.mp4 output.gif 

    }
    ~Mundo(){};
};

#endif