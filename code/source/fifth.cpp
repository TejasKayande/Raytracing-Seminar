
#include "util/image.h"
#include "util/vector.h"
#include "util/color.h"
#include "util/objects.h"

const int WIDTH  = 1000;
const int HEIGHT = 800;

Sphere spheres[2];

Vec3 camera_pos(0.0f, 0.0f, -1.0f);

// NOTE(Tejas): direction of light (it is actually inversed!)
Vec3 light_dir = Vec3::normalize(Vec3(+0.5f, +0.5f, +0.5f));

Color evalPixel(Vec2 coord) {

    // the FOV 
    float focal_point = 1.0f;

    // the ray from the focal point towards the scene
    Vec3 ray_dir(coord.x, coord.y, focal_point);

    // figures out what need to be rendered without streching image
    ray_dir = Vec3::normalize(ray_dir - camera_pos);

    // the actual camera when the calculation are done regarding FOV
    Ray camera(camera_pos, ray_dir);

    for (auto &sphere : spheres) {
        
        float hit_dist = sphere.intersects(camera);

        if (hit_dist != -1.0f) {

            Vec3 hit_point = camera.ori + camera.dir * hit_dist;
            Vec3 hit_point_normal = Vec3::normalize(hit_point - sphere.center);

            // NOTE(Tejas): dot product gives angle between two vectors by |a|*|b|*cos(angle)
            //              here a and b are normalized so float f -> cos(angle)
            float f = Vec3::dot(hit_point_normal, light_dir * -1);

            // NOTE(Tejas): the light direction will be opposite
            //              to what is specified because the angle in cos(a)
            // Color color = (hit_point + Vec3(1.0f, 1.0f, 1.0f) / 2) * f;
            Color color = sphere.material * f;

            return Color(color);
        }
    }

    // for a black background
    return Color(coord.y * 1.5f, coord.y * 1.5f, coord.y * 1.5f);
}

void render() {
    
    float aspect_ratio = (float)WIDTH / (float)HEIGHT;

    for (int x = 0; x < WIDTH; x++) {

        for (int y = 0; y < HEIGHT; y++) {

            // NOTE(Tejas): making the coords to be from 0 to 1
            Vec2 coord((float)x / (float)WIDTH, (float)y / (float)HEIGHT);

            // NOTE(Tejas): making the screen to be from -1 to 1
            coord.x = coord.x * 2.0f - 1.0f;
            coord.y = coord.y * 2.0f - 1.0f;

            // NOTE(Tejas): in case the screen is not perfect square
            coord.y = coord.y / aspect_ratio;

            Color c = Color::convertToRGB(evalPixel(coord));

            putPixel(x, y, c);
        }
    }
}

int main(void) {

    if (initImage(WIDTH, HEIGHT, "images/fifth.ppm") != 0) return -1;

    spheres[0] = Sphere(Vec3(-0.2f, +0.0f, +0.1f), 0.2f, Color(0.0, 1.0, 1.0f));
    spheres[1] = Sphere(Vec3(+0.2f, +0.0f, +0.1f), 0.2f, Color(1.0, 0.0, 1.0f));

    render();

    writePPM();
    closeImage();

    return 0;
}
