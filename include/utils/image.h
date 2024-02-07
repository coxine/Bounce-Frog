#ifndef INCLUDE_UTILS_IMAGE_H_
#define INCLUDE_UTILS_IMAGE_H_

typedef struct {
    int height;
    int width;
    int x;
    int y;
    char *name;
    char *file;
} Image;

#include <common.h>

Image *InitImage(char *file, int height, int width, char *name, int x, int y);
void LoadImage(App *app, Image *img);

#endif