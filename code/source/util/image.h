
#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "base.h"
#include "color.h"

struct Image {

    LPCSTR output_file;
    HANDLE file_handle;

    int width, height;

    void *buffer;
    int pitch;
};

int initImage(int width, int height, const char* file_name);
void closeImage();

void writePPM();
void putPixel(int x, int y, Color color);

#endif // _IMAGE_H_
