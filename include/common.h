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

#include <utils/types.h>

#include <utils/button.h>
#include <utils/image.h>
#include <utils/quit.h>
#include <utils/style.h>

#include <event.h>
#include <startPage.h>

extern App app;

#define HANDLE_ERROR(msg)                 \
    printf(msg ": %s\n", SDL_GetError()); \
    exit(EXIT_FAILURE);

#endif