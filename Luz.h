#ifndef LUZ_H
#define LUZ_H

#include "vec3.h"

class Luz {
public:
    float intensidad;
    vec3 pos, color;
    Luz(){}
    Luz(vec3 _pos, vec3 _color, float _intensidad) {
        pos = _pos;
        color = _color;
        intensidad = _intensidad;
    }
    void set(vec3 _pos, vec3 _color, float _intensidad) {
        pos = _pos;
        color = _color;
        intensidad = _intensidad;
    }
    ~Luz(){};
};

#endif