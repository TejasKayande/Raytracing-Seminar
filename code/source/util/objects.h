
#ifndef _OBJECTS_H_
#define _OBJECTS_H_

#include "base.h"
#include "vector.h"
#include "color.h"

struct Ray {

    // NOTE(Tejas): Equation for a point on ray:
    //              P(x,y,z) = O(x,y,z) + D(x,y,z) * t

    Vec3 ori; // O (origin)
    Vec3 dir; // D (direction)

    Ray(Vec3 ori, Vec3 dir)
        : ori(ori), dir(dir) {}
};

struct Sphere {

    // NOTE(Tejas): Equation for a sphere:
    //              (x - h)^2 + (y - k)^2 + (z - l)^2 = r^2
    
    Vec3 center;  // (h,k,l)
    float radius;
    Color material;

    Sphere() :
        center(Vec3(0.0f, 0.0f, 0.0f)), radius(0.3f),
        material(Color(255.0f, 255.0f, 255.0f)) {}

    Sphere(Vec3 center, float radius, Color material) : 
        center(center), radius(radius), material(material) {}

    float intersects(Ray ray);
};

#endif // _OBJECTS_H_
