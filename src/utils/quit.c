#include "quit.h"

void Quit(SDL_Window *window, SDL_Renderer *renderer)
{
    // Destroy window
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    // Quit SDL subsystems
    SDL_Quit();
}