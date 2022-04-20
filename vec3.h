#ifndef VEC3_H
#define VEC3_H

#include <cmath>

class vec3 {
public:
    float x,y,z;
    vec3(): x(float(0)), y(float(0)), z(float(0)) {}
    vec3(float _x): x(_x), y(_x), z(_x) {}
    vec3(float _x, float _y, float _z) { x=_x; y=_y; z=_z; }
    vec3 operator+(vec3 v) { return vec3(x+v.x, y+v.y, z+v.z); }
    vec3 operator-(vec3 v) { return vec3(x-v.x, y-v.y, z-v.z); }
    vec3 operator-() { return vec3(-x,-y,-z); }
    vec3 operator*(float s) { return vec3(x*s, y*s, z*s); }
    vec3 operator*(vec3 v) { return vec3(x*v.x, y*v.y, z*v.z); }
    vec3 operator/(float s) { return vec3(x/s, y/s, z/s); }
    friend vec3 operator*(float s, vec3 v) { return vec3(v.x*s, v.y*s, v.z*s); }
    friend vec3 operator/(float s, vec3 v) { return vec3(s/v.x, s/v.y, s/v.z); }
    float prod_punto(vec3 v) {
        return x*v.x + y*v.y + z*v.z;
    }
    vec3& operator /= (float s) {
        x /= s; y /= s; z /= s; return *this;
    }
    vec3 prod_cruz(vec3 v) {
        return vec3(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
    }
    double modulo() {
        return sqrt(x*x + y*y + z*z);
    }
    void normalize() {
        double m = modulo();
        x /= m;
        y /= m;
        z /= m;
    }
    void max_to_one() {
        float max_value = std::max(std::max(x, y), z);
        if(max_value > 1.0) {
            x /= max_value;
            y /= max_value;
            z /= max_value;
        } 
    }
    ~vec3(){};
};


#endif