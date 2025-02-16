
#ifndef _COLOR_H_
#define _COLOR_H_

#include "base.h"
#include "vector.h"

// NOTE(Tejas): The color in the actual pixel buffer is a 32-bit integer,
//              this is just a high level abstraction for convenience.

struct Color {

    f32 r, g, b;

    Color() :
        r(0), g(0), b(0) {}

    Color(u32 hex_color) :
        r((hex_color << 16) & 0xFF),
        g((hex_color <<  8) & 0xFF),
        b((hex_color <<  0) & 0xFF) {}

    Color(f32 r, f32 g, f32 b) :
        r(MIN(255.0f, r)), g(MIN(255.0f, g)), b(MIN(255.0f, b)) {}

    Color(Vec3 vec3)
        :r(vec3.x), g(vec3.y), b(vec3.z) {}

    static Color convertToRGB(Color color);
    static Color convertTo0to1(Color color);

    Color operator+(float scalar) const;
    Color operator-(float scalar) const;
    Color operator*(float scalar) const;
    Color operator/(float scalar) const;
};

#endif // _COLOR_H_
