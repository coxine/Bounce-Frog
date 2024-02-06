#include <utils/quit.h>

void Quit(App *app)
{
    // Destroy window
    SDL_FreeSurface(app->windowIcon);
    SDL_DestroyWindow(app->window);
    SDL_DestroyRenderer(app->renderer);
    // Quit SDL subsystems
    SDL_Quit();
}