#include <utils/quit.h>

void DestroyWindow(App *app)
{
    SDL_FreeSurface(app->windowIcon);
    SDL_DestroyWindow(app->window);
    SDL_DestroyRenderer(app->renderer);
}
void Quit(App *app)
{
    DestroyWindow(app);
    // DestroyStartPage();
    SDL_Quit();
}