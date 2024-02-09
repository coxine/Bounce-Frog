#include <utils/style.h>

void LoadBgColor(App *app, SDL_Color bgColor)
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
}

void ChangeBgColor(App *app, SDL_Color bgColor)
{
    LoadBgColor(app, bgColor);
    SDL_RenderPresent(app->renderer);
}

void FillRect(SDL_Color bgColor, int x, int y, int width, int height)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    SDL_Renderer *renderer = app.renderer;
    SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
    SDL_RenderFillRect(renderer, &rect);
}
