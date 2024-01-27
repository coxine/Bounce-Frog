#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdbool.h>
#include <stdio.h>
#undef main
// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main()
{
    // The window we'll be rendering to
    SDL_Window *window = NULL;

    // The surface contained by the window
    SDL_Surface *screenSurface = NULL;

    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    ING_Init(IMG_INIT_JPG | IMG_INIT_PNG);

    // Create window
    window = SDL_CreateWindow("Hell Wood", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    // Get window surface
    // screenSurface = SDL_GetWindowSurface(window);

    // Fill the surface white
    // SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
    // // Update the surface
    // SDL_UpdateWindowSurface(window);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0x60, 0xc0, 0xa0, 0xff);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(1500);

    for (int x = 1; x <= 600; x++) {

        SDL_SetRenderDrawColor(renderer, 0x60, 0xc0, 0xa0, 0xff);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0xf0, 0x00, 0x00, 0xff);
        SDL_Rect rect = {.x = x, .y = 100, .w = 100, .h = 100};
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(5);
    }
    // Hack to get window to stay up
    // SDL_Event e;
    // bool quit = false;
    // while (quit == false) {
    //     while (SDL_PollEvent(&e)) {
    //         if (e.type == SDL_QUIT)
    //             quit = true;
    //     }
    // }

    // Destroy window
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}
