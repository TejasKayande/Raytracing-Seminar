
#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "base.h"

struct Vec2 {

    float x;
    float y;

    Vec2(float x, float y) 
        : x(x), y(y) {}

    Vec2 operator+(Vec2 vec) const;
    Vec2 operator-(Vec2 vec) const;
    Vec2 operator*(float scalar) const;
    Vec2 operator/(float scalar) const;
};

struct Vec3 {

    float x;
    float y;
    float z;

    Vec3(float x, float y, float z) 
        : x(x), y(y), z(z) {}

    Vec3(Vec2 vec2, float z)
        : x(vec2.x), y(vec2.y), z(z) {}

    static float dot(Vec3 vec1, Vec3 vec2);
    static Vec3 normalize(Vec3 vec);

    float magnitude() const;

    Vec3 operator+(Vec3 vec) const;
    Vec3 operator-(Vec3 vec) const;
    Vec3 operator*(float scalar) const;
    Vec3 operator/(float scalar) const;
};

#endif // _VECTOR_H_
