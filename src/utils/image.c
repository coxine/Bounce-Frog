#include <utils/image.h>

void LoadImage(App *app, Image *img)
{
    // Create Surface & Rect
    SDL_Surface *src = IMG_Load("../static/img/Title.svg");
    if (src == NULL) {
        printf("Load %s : %s\n", img->name, SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_Surface *dest = SDL_CreateRGBSurface(0, 800, 600, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
    SDL_Rect *rect = malloc(sizeof(SDL_Rect));
    rect->x = img->x;
    rect->y = img->y;
    rect->w = img->width;
    rect->h = img->height;

    // Render it
    SDL_BlitScaled(src, NULL, dest, NULL);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(app->renderer, dest);
    SDL_RenderCopy(app->renderer, texture, NULL, rect);
    SDL_RenderPresent(app->renderer);

    // Kill what you've created
    SDL_FreeSurface(dest);
    SDL_FreeSurface(src);
    SDL_DestroyTexture(texture);
    free(rect);
}