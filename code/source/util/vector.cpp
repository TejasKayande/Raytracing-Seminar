
#include "vector.h"

// Vec2
Vec2 Vec2::operator+(Vec2 vec) const {
    return Vec2(x + vec.x, y + vec.y);
}

Vec2 Vec2::operator-(Vec2 vec) const {
    return Vec2(x - vec.x, y - vec.y);
}

Vec2 Vec2::operator*(float scalar) const {
    return Vec2(x * scalar, y * scalar);
}

Vec2 Vec2::operator/(float scalar) const {
    return Vec2(x / scalar, y / scalar);
}

// Vec3
float Vec3::dot(Vec3 vec1, Vec3 vec2) {
    return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

float Vec3::magnitude() const {
    return sqrt((x * x) + (y * y) + (z * z));
}

Vec3 Vec3::normalize(Vec3 vec) {

    float mag = vec.magnitude();

    if (mag != 0.0) return (vec * (1.0f / mag));

    return vec;
}

Vec3 Vec3::operator+(Vec3 vec) const {
    return (Vec3(x + vec.x, y + vec.y, z + vec.z));
}

Vec3 Vec3::operator-(Vec3 vec) const {
    return Vec3(x - vec.x, y - vec.y, z - vec.z);
}

Vec3 Vec3::operator*(float scalar) const {
    return Vec3(x * scalar, y * scalar, z * scalar); 
}

Vec3 Vec3::operator/(float scalar) const {

    if (scalar == 0) return *this;
    return Vec3(x / scalar, y / scalar, z / scalar); 
}
