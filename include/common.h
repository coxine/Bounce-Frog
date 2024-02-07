#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *windowIcon;
    int curScene;
} App;

extern App app;

#include <utils/button.h>
#include <utils/image.h>
#include <utils/quit.h>
#include <utils/style.h>

#define HANDLE_ERROR(msg)                 \
    printf(msg ": %s\n", SDL_GetError()); \
    exit(EXIT_FAILURE);

#endif