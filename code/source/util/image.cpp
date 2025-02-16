
#include "image.h"

static Image image;

int initImage(int width, int height, const char* file_name) {

    image.output_file = file_name;

    image.width = width;
    image.height = height;

    image.file_handle = CreateFile(image.output_file, GENERIC_WRITE, 0, nullptr,
                                   CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

    if (image.file_handle == INVALID_HANDLE_VALUE) return -1;


    // NOTE(Tejas): Allocating memory to a buffer so that we can edit the contents
    //              of the program in the buffer and write at the end only once
    //              after the scene is completed.

    // NOTE(Tejas): Each pixel consists of Red, Green and Blue component. Each of those
    //              occupies 1 byte of memory so the buffer calculation turns out to be
    //              the width times the height time the space required by individual pixel.
    //              We consider 4 bytes insted of 3 bytes so that the extra 1 byte makes it
    //              a 32-bit integer and eaiser to deal with.

    int bytes_per_pixel = 4;
    image.pitch = image.width * bytes_per_pixel;

    int size =  (image.width * image.height) * bytes_per_pixel;
    image.buffer = (void*)VirtualAlloc(nullptr, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    if (image.buffer == nullptr) return -1;

    memset(image.buffer, 0xFF, size);

    return 0;
}

void closeImage() {
 
    if (image.buffer) VirtualFree(image.buffer, 0, MEM_RELEASE);

    FlushFileBuffers(image.file_handle);
    if (image.file_handle) CloseHandle(image.file_handle);
}

void writePPM() {

    // NOTE(Tejas): here we are writing the pixel data from our buffer in memory
    //              into a file in the PPM format.

    // NOTE(Tejas): you can look more into PPM format at:
    //              https://netpbm.sourceforge.net/doc/ppm.html

    char meta_data[256];
    wsprintf(meta_data, "P3 %d %d \n255\n", image.width, image.height);

    DWORD bytes_written;
    WriteFile(image.file_handle, meta_data, strlen(meta_data), &bytes_written, NULL);

    u8 *row = (u8*) image.buffer;
    for (int i = 0; i < image.height; i++) {

        u32 *pixel = (u32*)row;

        for (int j = 0; j < image.width; j++) {

            u8 r = (*pixel >> 16) & 0xFF;
            u8 g = (*pixel >>  8) & 0xFF;
            u8 b = (*pixel >>  0) & 0xFF;

            char color_data[256];
            wsprintf(color_data, "%d %d %d ", r, g, b);
            WriteFile(image.file_handle, color_data, strlen(color_data), &bytes_written, NULL);

            pixel++;
        }

        row += image.pitch;

        WriteFile(image.file_handle, "\n", 1, &bytes_written, NULL);
    }
}

void putPixel(int x, int y, Color color) {
    
    // Out of bounds
    if (x < 0 || x >= image.width || y < 0 || y >= image.height) return;

    u8 r = color.r;
    u8 g = color.g;
    u8 b = color.b;

    u32 c = 0xFF << 24 | r << 16 | g << 8 | b;

   u32* ptr = (u32*) image.buffer;
    ptr[y * image.width + x] = c;
}
