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
        DoButton(app->startpage->godMode);
        DoButton(app->startpage->startGame);
        break;
    case SDL_KEYDOWN:
        if ((*(app->event)).key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
            DrawQuitPage(app);
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
        if ((*(app->event)).key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
            DrawQuitPage(app);
        }
        if (!app->keyPress[scanCode]) {
            app->keyTimestamp[scanCode][0] = (*(app->event)).key.timestamp;
            app->keyPress[scanCode] = true;
        }
        break;
    case SDL_KEYUP:
        if (scanCode == SDL_SCANCODE_SPACE) {
            app->keyTimestamp[scanCode][1] = (*(app->event)).key.timestamp;
            app->keyPress[scanCode] = false;
            Uint32 frogHopTime = GetFrogHopTimeFromSpace(app);
            Move(app, &(app->gamepage->frog), 0, -0.5 * frogHopTime / 32, 0, FROG_HOP_DY, 2 * frogHopTime / 32 + 1);
        }
        break;
    case SDL_MOUSEBUTTONDOWN:
        if (((*(app->event)).button.button == SDL_BUTTON_LEFT) && !app->mousePress) {
            app->mouseTimestamp[0] = (*(app->event)).button.timestamp;
            app->mousePress = true;
        }
        break;
    case SDL_MOUSEBUTTONUP:
        if ((*(app->event)).button.button == SDL_BUTTON_LEFT) {
            app->mouseTimestamp[1] = (*(app->event)).button.timestamp;
            app->mousePress = false;
            Uint32 frogHopTime = GetFrogHopTimeFromMouse(app);
            Move(app, &(app->gamepage->frog), 0, -0.5 * frogHopTime / 32, 0, FROG_HOP_DY, 2 * frogHopTime / 32 + 1);
        }

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
    case SDL_KEYDOWN:
        if ((*(app->event)).key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
            DrawQuitPage(app);
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
        UpdateButton(app, app->quitpage->home);
        UpdateButton(app, app->quitpage->startGame);
        break;
    case SDL_MOUSEBUTTONDOWN:
        DoButton(app->quitpage->kontinue);
        DoButton(app->quitpage->quit);
        DoButton(app->quitpage->home);
        DoButton(app->quitpage->startGame);
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

Uint32 GetFrogHopTimeFromSpace(App *app)
{
    if (GetKeyPressTime(app, SDL_SCANCODE_SPACE) > MAX_HOP_TIME) {
        return MAX_HOP_TIME;
    }

    return GetKeyPressTime(app, SDL_SCANCODE_SPACE);
}

Uint32 GetMousePressTime(App *app)
{
    Uint32 press_time = app->mouseTimestamp[0];
    Uint32 release_time = app->mouseTimestamp[1];
    if (press_time > 0 && release_time >= press_time) {
        return release_time - press_time;
    } else {
        return 0;
    }
}

Uint32 GetFrogHopTimeFromMouse(App *app)
{
    if (GetMousePressTime(app) > MAX_HOP_TIME) {
        return MAX_HOP_TIME;
    }

    return GetMousePressTime(app);
}