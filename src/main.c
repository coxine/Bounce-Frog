#include <main.h>

int main()
{
    SDL_Window *SDLWindow = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Init SDL: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    };
    // create window
    SDLWindow = SDL_CreateWindow("跳一跳", START_X, START_Y, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer *windowRnd = SDL_CreateRenderer(SDLWindow, -1, SDL_RENDERER_ACCELERATED);
    changeBgColor(windowRnd, windowStyle.color);
    SDL_Delay(1500);

    // Hack to get window to stay up
    // SDL_Event e;
    // bool quit = false;
    // while (quit == false) {
    //     while (SDL_PollEvent(&e)) {
    //         if (e.type == SDL_QUIT)
    //             quit = true;
    //     }
    // }
    Quit(SDLWindow, windowRnd);
    return 0;
}