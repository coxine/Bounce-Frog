#ifndef INCLUDE_UTILS_IMAGE_H_
#define INCLUDE_UTILS_IMAGE_H_
#include <common.h>

typedef struct {
    int height;
    int width;
    int x;
    int y;
    char* name;
    char* file;
} Image;

void LoadImage(App *app,Image* img);

#endif