
#include "color.h"

Color Color::operator+(float scalar) const {
    return Color(r + scalar, g + scalar, b + scalar);
}

Color Color::operator-(float scalar) const {
    return Color(r - scalar, g - scalar, b - scalar);
}

Color Color::operator*(float scalar) const {
    return Color(r * scalar, g * scalar, b * scalar);
}

Color Color::operator/(float scalar) const {
    if (scalar == 0) return *this;
    return Color(r / scalar, g / scalar, b / scalar);
}

Color Color::convertToRGB(Color color) {

    return Color(MIN(255.0f, MAX(0.0f, color.r * 255.0f)),
                 MIN(255.0f, MAX(0.0f, color.g * 255.0f)),
                 MIN(255.0f, MAX(0.0f, color.b * 255.0f)));
}

Color Color::convertTo0to1(Color color) {

    return Color(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f);
}
