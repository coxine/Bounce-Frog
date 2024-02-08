#include <utils/quit.h>

void DestroyWindow(App *app)
{
    SDL_FreeSurface(app->windowIcon);
    SDL_DestroyWindow(app->window);
    SDL_DestroyRenderer(app->renderer);
    TTF_CloseFont(app->font);
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
}