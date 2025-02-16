
#include "objects.h"

float Sphere::intersects(Ray ray) {

    /************************************NOTE(Tejas)***************************************
    *                                                                                     *
    * return the distance from the origin of the Ray to the point of contact.             *
    * if any contact, otherwise returns -1                                                *
    *                                                                                     *
    * if the origin of the ray is O(x,y,z) and Direction is D(x,y,z) then the             *
    * quadratic equation showing the relation between the sphere and the ray is           *
    * give as follows:                                                                    *
    *                                                                                     *
    * sphere at the origin (0, 0, 0)                                                      *
    * (Dx^2 + Dy^2 + Dz^2)t^2 + 2(OxDx + OyDy + OzDz)t + Ox^2 + Oy^2 + Oz^2 - r^2 = 0     *
    * where t is the distance from ray origin to hit point                                *
    *                                                                                     *
    * comparing the above quadratic equation with ax^2 + bx + c = 0                       *
    * we have,                                                                            *
    *           x = t                                                                     *
    *           a = (Dx^2 + Dy^2 + Dz^2)                                                  *
    *           b = 2(OxDx + OyDy + OzDz)t                                                *
    *           c = Ox^2 + Oy^2 + Oz^2 - r^2 = 0                                          *
    **************************************************************************************/


    // taking the distance from the camera origin and the center of the sphere
    Vec3 oc = ray.ori - center;

    float a = 1.0f; // since the ray direction is already normalized
    float b = 2.0f * Vec3::dot(oc, ray.dir);
    float c = Vec3::dot(oc, oc) - radius * radius;

    // b^2 - 4ac
    float discriminant = (b * b) - (4.0f * a * c);

    if (discriminant >= 0) {

        // only calculating the closest hitpoint
        //(-b - (b^2 - 4ac)) / 2
        return (-b - sqrt(discriminant)) / (2 * a);
        
    }

    // no connection between ray and the sphere
    return -1.0f;
}
