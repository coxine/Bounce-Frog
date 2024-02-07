#include <utils/image.h>

void LoadImage(App *app, Image *img)
{
    img->src = IMG_Load("../static/img/Title.svg");
    if (img->src == NULL) {
        printf("Load %s : %s\n", img->name, SDL_GetError());
        exit(EXIT_FAILURE);
    }
    img->dest = SDL_CreateRGBSurface(0, 800, 600, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
    img->rect.x = img->x;
    img->rect.y = img->y;
    img->rect.w = img->width;
    img->rect.h = img->height;
    SDL_BlitScaled(img->src, NULL, img->dest, NULL);
    SDL_Texture *textureimg = SDL_CreateTextureFromSurface(app->renderer, img->dest);
    SDL_RenderCopy(app->renderer, textureimg, NULL, &img->rect);
    SDL_RenderPresent(app->renderer);
    SDL_FreeSurface(img->dest);
    SDL_FreeSurface(img->src);
}