#include <utils/style.h>

void changeBgColor(SDL_Renderer *renderer, Color color)
{
    int r = color.r;
    int g = color.g;
    int b = color.b;
    int a = color.a;

    if (r > 0xff || g > 0xff || b > 0xff || a > 0xff) {
        printf("Error");
        return;
    }
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}