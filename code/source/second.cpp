
#include "util/image.h"

void drawLine(int x1, int y1, int x2, int y2);
void drawCricle(int xc, int yc, int r);

int main(void) {

    if (initImage(800, 800, "images/second1.ppm") != 0) return -1;

    for (int i = 0; i < 800; i++) {
        for (int j = 0; j < 800; j++) {
            Color c(255.0f, 0.0f, 255.0f);
            putPixel(j, i, c);
        }
    }

    // drawLine(50, 50, 500, 500);
    // drawCricle(800/2, 800/2, 50);

    writePPM();
    closeImage();
    return 0;
}

void drawLine(int x1, int y1, int x2, int y2) {

    int m_new = 2 * (y2 - y1); 
    int slope_error_new = m_new - (x2 - x1); 

    for (int x = x1, y = y1; x <= x2; x++) { 
        putPixel(x, y, 0x00);
        slope_error_new += m_new; 
  
        if (slope_error_new >= 0) { 
            y++; 
            slope_error_new -= 2 * (x2 - x1); 
        } 
    } 
}

void drawCricle(int xc, int yc, int r) {

    int x = 0, y = r;
    int d = 3 - 2 * r;

    putPixel(xc+x, yc+y, 0xFFFF00FF);
    putPixel(xc-x, yc+y, 0xFFFF00FF);
    putPixel(xc+x, yc-y, 0xFFFF00FF);
    putPixel(xc-x, yc-y, 0xFFFF00FF);
    putPixel(xc+y, yc+x, 0xFFFF00FF);
    putPixel(xc-y, yc+x, 0xFFFF00FF);
    putPixel(xc+y, yc-x, 0xFFFF00FF);
    putPixel(xc-y, yc-x, 0xFFFF00FF);

    while (y >= x){
      
        if (d > 0) {
            y--; 
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;

        x++;
        
        putPixel(xc+x, yc+y, 0xFFFF00FF);
        putPixel(xc-x, yc+y, 0xFFFF00FF);
        putPixel(xc+x, yc-y, 0xFFFF00FF);
        putPixel(xc-x, yc-y, 0xFFFF00FF);
        putPixel(xc+y, yc+x, 0xFFFF00FF);
        putPixel(xc-y, yc+x, 0xFFFF00FF);
        putPixel(xc+y, yc-x, 0xFFFF00FF);
        putPixel(xc-y, yc-x, 0xFFFF00FF);
    }   
}
