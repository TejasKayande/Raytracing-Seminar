
#include "util/image.h"
#include "util/vector.h"
#include "util/color.h"
#include "util/objects.h"

const int WIDTH  = 1000;
const int HEIGHT = 800;

Sphere sphere(Vec3(0.0f, 0.0f, 0.0f), 0.3f, Color(0.0, 1.0, 0.0f));
Vec3 camera_pos(0.0f, 0.0f, -1.0f);

Color evalPixel(Vec2 coord) {

    Vec3 ray_dir(Vec3::normalize(Vec3(coord.x, coord.y, 1.0f)));
    Ray camera(camera_pos, ray_dir);

    float hit_dist = sphere.intersects(camera);

    if (hit_dist != -1.0f) return sphere.material;

    return Color(0.0f, 0.0f, 0.0f);
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

    if (initImage(WIDTH, HEIGHT, "images/third.ppm") != 0) return -1;

    render();

    writePPM();
    closeImage();

    return 0;
}
