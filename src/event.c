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
            case GameScene:
                GameSceneEvent(app);
                break;
            case OverScene:
                OverSceneEvent(app);
                break;
            case QuitScene:
                QuitSceneEvent(app);
                break;
            default:
                break;
            }
        }
        SDL_Delay(5);
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
            DrawOverPage(app); // for test
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

void GameSceneEvent(App *app)
{
    SDL_Scancode scanCode = (*(app->event)).key.keysym.scancode;
    switch ((*(app->event)).type) {
    case SDL_QUIT:
        DrawQuitPage(app);
        break;
    case SDL_KEYDOWN:
        if (!app->keyPress[scanCode]) {
            app->keyTimestamp[scanCode][0] = (*(app->event)).key.timestamp;
            app->keyPress[scanCode] = true;
        }
        break;
    case SDL_KEYUP:
        app->keyTimestamp[scanCode][1] = (*(app->event)).key.timestamp;
        app->keyPress[scanCode] = false;
        break;
    default:
        break;
    }
}

void OverSceneEvent(App *app)
{
    switch ((*(app->event)).type) {
    case SDL_QUIT:
        DrawQuitPage(app);
        break;
    case SDL_MOUSEMOTION:
        UpdateButton(app, app->overpage->home);
        UpdateButton(app, app->overpage->quit);
        break;
    case SDL_MOUSEBUTTONDOWN:
        DoButton(app->overpage->home);
        DoButton(app->overpage->quit);
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

Uint32 GetKeyPressTime(App *app, SDL_Scancode scancode)
{
    Uint32 press_time = app->keyTimestamp[scancode][0];
    Uint32 release_time = app->keyTimestamp[scancode][1];
    if (press_time > 0 && release_time >= press_time) {
        return release_time - press_time;
    } else {
        return 0;
    }
}