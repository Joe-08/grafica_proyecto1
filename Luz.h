#ifndef LUZ_H
#define LUZ_H

#include "vec3.h"

class Luz {
public:
    vec3 pos, color;
    Luz(){}
    Luz(vec3 _pos, vec3 _color) {
        pos = _pos;
        color = _color;
    }
    void set(vec3 _pos, vec3 _color) {
        pos = _pos;
        color = _color;
    }
    ~Luz(){};
};

#endif