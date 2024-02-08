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
                switch ((*(app->event)).type) {
                case SDL_QUIT:
                    DrawQuitPage(app);
                    break;
                case SDL_MOUSEMOTION:
                    if (isHover(app->startpage->startGame)) {
                        LoadImage(app, app->startpage->startGame->imgOnHover);
                    } else {
                        LoadImage(app, app->startpage->startGame->img);
                    }
                    if (isHover(app->startpage->godMode)) {
                        LoadImage(app, app->startpage->godMode->imgOnHover);
                    } else {
                        LoadImage(app, app->startpage->godMode->img);
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (isClick(app->startpage->startGame)) {
                        puts("111");
                    }
                    if (isClick(app->startpage->godMode)) {
                        puts("222");
                    }
                    break;
                default:
                    break;
                }
                break;

            case QuitScene:
                switch ((*(app->event)).type) {
                case SDL_MOUSEMOTION:
                    if (isHover(app->quitpage->kontinue)) {
                        LoadImage(app, app->quitpage->kontinue->imgOnHover);
                    } else {
                        LoadImage(app, app->quitpage->kontinue->img);
                    }
                    if (isHover(app->quitpage->quit)) {
                        LoadImage(app, app->quitpage->quit->imgOnHover);
                    } else {
                        LoadImage(app, app->quitpage->quit->img);
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (isClick(app->quitpage->kontinue)) {
                        DrawStartPage(app);
                        return;
                    }
                    if (isClick(app->quitpage->quit)) {
                        DestroyWindow(app);
                        exit(EXIT_SUCCESS);
                    }
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
        SDL_Delay(2);
    }
}
