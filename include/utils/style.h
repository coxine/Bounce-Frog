#ifndef INCLUDE_UTILS_style_H_
#define INCLUDE_UTILS_style_H_

#include "SDL2/SDL.h"
#include <stdio.h>

typedef struct Color {
    int r;
    int g;
    int b;
    int a;
} color;

typedef struct ObjectStyle {
    color color;
} objectStyle;

void changeBgColor(SDL_Renderer *renderer, color color);
#endif