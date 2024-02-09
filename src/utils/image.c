#include <utils/image.h>

Image *InitImage(char *file, int height, int width, char *name, int x, int y)
{
    Image *img = malloc(sizeof(Image));
    if (img == NULL) {
        exit(EXIT_FAILURE);
    }
    img->height = height;
    img->width = width;
    img->x = x;
    img->y = y;
    img->file = malloc(strlen(file) + 1);
    strcpy(img->file, file);
    img->name = malloc(strlen(name) + 1);
    strcpy(img->name, name);
    return img;
}

// 更新图片长宽位置
void UpdateImage(Image *img, char *file, int height, int width, char *name, int x, int y)
{
    img->height = height;
    img->width = width;
    img->x = x;
    img->y = y;
    img->file = malloc(strlen(file) + 1);
    strcpy(img->file, file);
    img->name = malloc(strlen(name) + 1);
    strcpy(img->name, name);
}

// 将图片输出到屏幕
void LoadImage(App *app, Image *img)
{
    // Create Surface & Rect
    SDL_Surface *src = IMG_Load(img->file);
    if (src == NULL) {
        printf("Load %s : %s\n", img->name, SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_Surface *dest = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
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

void DestroyImage(Image *img)
{
    free(img->file);
    free(img->name);
    free(img);
}