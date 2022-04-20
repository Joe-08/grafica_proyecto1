#ifndef RAYO_H
#define RAYO_H

#include "vec3.h"

class Rayo {
public:
    vec3 origen, direccion;
    Rayo(){}
    Rayo(vec3 _origen, vec3 _direccion) {
        origen = _origen;
        direccion = _direccion;
    }
    ~Rayo(){};
};

#endif