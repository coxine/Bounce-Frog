#include <event.h>

void InitEvent(App *app)
{
    app->event = malloc(sizeof(SDL_Event));
    if (app->event == NULL) {
        puts("Fail to Init Event");
        exit(EXIT_FAILURE);
    }
}

void DoEvent(App *app)
{
    InitEvent(app);
    while (1) {
        while (SDL_PollEvent(app->event)) {
            switch (app->curScene) {
            case StartScene:
                StartSceneEvent(app);
                break;

            case QuitScene:
                QuitSceneEvent(app);
                break;
            default:
                break;
            }
        }
        SDL_Delay(2);
    }
}

void StartSceneEvent(App *app)
{
    switch ((*(app->event)).type) {
    case SDL_QUIT:
        DrawQuitPage(app);
        break;
    case SDL_MOUSEMOTION:
        UpdateButton(app, app->startpage->startGame);
        UpdateButton(app, app->startpage->godMode);
        break;
    case SDL_MOUSEBUTTONDOWN:
        if (isClick(app->startpage->startGame)) {
            puts("111");
            return;
        }
        if (isClick(app->startpage->godMode)) {
            puts("222");
            return;
        }
        break;
    default:
        break;
    }
}

void QuitSceneEvent(App *app)
{
    switch ((*(app->event)).type) {
    case SDL_MOUSEMOTION:
        UpdateButton(app, app->quitpage->kontinue);
        UpdateButton(app, app->quitpage->quit);
        break;
    case SDL_MOUSEBUTTONDOWN:
        DoButton(app->quitpage->kontinue);
        DoButton(app->quitpage->quit);
        break;
    default:
        break;
    }
}
