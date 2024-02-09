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
    if (app->gamepage->isGodMode) {
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
                Uint32 frogHopTime = GetFrogHopTimeFromDistance(app);
                printf("%u\n", frogHopTime);
                GodMoveFlorrAndFrog(app, frogHopTime, fmin(1, app->gamepage->maxFlorr - 2), app->gamepage->maxFlorr);
                app->gamepage->curFlorr++;
                InitFlorr(app->gamepage->maxFlorr);
                app->curScore += 4;
                DrawScore(app);
            }
            break;
        default:
            break;
        }
    } else {
        SDL_Scancode scanCode = (*(app->event)).key.keysym.scancode;
        switch ((*(app->event)).type) {
        case SDL_QUIT:
            DrawQuitPage(app);
            break;
        case SDL_KEYDOWN:
            SDL_RenderPresent(app->renderer);
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
                MoveFlorrAndFrog(app, frogHopTime, fmin(1, app->gamepage->maxFlorr - 2), app->gamepage->maxFlorr);
                app->gamepage->curFlorr++;
                InitFlorr(app->gamepage->maxFlorr);
                if (isCollide(&(app->gamepage->frog), &(app->gamepage->florr[app->gamepage->curFlorr]))) {
                    if (isCenter(&(app->gamepage->frog), &(app->gamepage->florr[app->gamepage->curFlorr]))) {
                        app->curScore += 4;
                    } else {
                        app->curScore += 2;
                    }
                    DrawScore(app);
                } else {
                    DrawOverPage(app);
                }
                break;
            }
        default:
            break;
        }
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

Uint32 GetFrogHopTimeFromDistance(App *app)
{
    int cur = app->gamepage->curFlorr;
    int next = cur + 1;
    int distance = app->gamepage->florr[cur].image->y - app->gamepage->florr[next].image->y;
    Uint32 time = distance / GP_FLORR_SPEED_Y;

    return time;
}