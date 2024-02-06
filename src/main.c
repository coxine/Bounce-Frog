#include <main.h>

App app;

int main()
{
    InitApp();
    StartUp();
    DisplayStartPage(&app);
    SDL_Event event;
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                Quit(&app);
                return 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                break;
            case SDL_MOUSEBUTTONUP:
                break;
            case SDL_KEYDOWN:
                break;
            case SDL_KEYUP:
                break;
            default:
                break;
            }
        }
        SDL_Delay(5);
    }
    return 0;
}

static void InitApp()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        HANDLE_ERROR("Init SDL");
    };

    if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG)) {
        HANDLE_ERROR("Init IMG");
    }
    if (!Mix_Init(MIX_INIT_MP3)) {
        HANDLE_ERROR("Init Mixer");
    }
    if (TTF_Init() == -1) {
        HANDLE_ERROR("Init TTF");
    }
}

static void StartUp()
{
    app.window = SDL_CreateWindow(WINDOW_TITLE, START_X, START_Y, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
    app.windowIcon = IMG_Load("../static/img/Icon.png");
    if (app.windowIcon == NULL) {
        HANDLE_ERROR("Load Icon");
    };
    SDL_SetWindowIcon(app.window, app.windowIcon);
    changeBgColor(app.renderer, windowStyle.color);
}