#include <startPage.h>

void DisplayStartPage(App *app)
{
    // SDL_Surface *surfaceStartpageTitle = IMG_Load("../static/img/Title.svg");
    // if (surfaceStartpageTitle == NULL) {
    //     HANDLE_ERROR("Load Startpage Title");
    // }
    // SDL_Texture *textureStartpageTitle = SDL_CreateTextureFromSurface(app->renderer, surfaceStartpageTitle);
    // SDL_Rect rectStartpageTitle = {.x = 0, .y = 0};
    // SDL_QueryTexture(textureStartpageTitle, NULL, NULL, &rectStartpageTitle.w, &rectStartpageTitle.h);
    // SDL_RenderCopy(app->renderer, textureStartpageTitle, NULL, &rectStartpageTitle);
    // SDL_RenderPresent(app->renderer);
    SDL_Surface *surfaceStartpageTitle = IMG_Load("../static/img/Title.svg");
    if (surfaceStartpageTitle == NULL) {
        HANDLE_ERROR("Load Startpage Title");
    }
    SDL_SetSurfaceBlendMode(surfaceStartpageTitle, SDL_BLENDMODE_NONE);
    SDL_Surface *out = SDL_CreateRGBSurface(0, 100, 100, surfaceStartpageTitle->format->BitsPerPixel,
                                            surfaceStartpageTitle->format->Rmask, surfaceStartpageTitle->format->Gmask, surfaceStartpageTitle->format->Bmask, surfaceStartpageTitle->format->Amask);
    SDL_BlitScaled(surfaceStartpageTitle, NULL, out, NULL);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(app->renderer, out);
    SDL_Rect rec = {10, 10, 110, 110};
    SDL_RenderCopy(app->renderer, tex, NULL, &rec);
}