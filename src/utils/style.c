#include <utils/style.h>

void changeBgColor(App *app, SDL_Color bgColor)
{
    int r = bgColor.r;
    int g = bgColor.g;
    int b = bgColor.b;
    int a = bgColor.a;

    if (r > 0xff || g > 0xff || b > 0xff || a > 0xff) {
        printf("Error");
        return;
    }
    SDL_SetRenderDrawColor(app->renderer, r, g, b, a);
    SDL_RenderClear(app->renderer);
    SDL_RenderPresent(app->renderer);
}