#ifndef INCLUDE_UTILS_IMAGE_H_
#define INCLUDE_UTILS_IMAGE_H_
#include <common.h>

typedef struct {
    SDL_Surface *src;
    SDL_Surface *dest;
    int height;
    int width;
    int x;
    int y;
    SDL_Rect rect;
    char* name;
    char* file;
} Image;

void LoadImage(App *app,Image* img);

#endif