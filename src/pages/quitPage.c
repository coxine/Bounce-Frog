#include <pages/quitPage.h>

QuitPage *InitQuitPage()
{
    QuitPage *quitpage = malloc(sizeof(QuitPage));
    if (quitpage == NULL) {
        puts("Fail to Init QuitPage");
        exit(EXIT_FAILURE);
    }
    quitpage->kontinue = InitButton(QP_KONTINUE_HEIGHT, QP_KONTINUE_WIDTH, QP_KONTINUE_X, QP_KONTINUE_Y, QP_KONTINUE_IMG, QP_KONTINUE_NAME, QP_KONTINUE_IMG_ON_HOV, &qpKontinueOnClick);
    quitpage->quit = InitButton(QP_QUIT_HEIGHT, QP_QUIT_WIDTH, QP_QUIT_X, QP_QUIT_Y, QP_QUIT_IMG, QP_QUIT_NAME, QP_QUIT_IMG_ON_HOV, &qpQuitOnClick);
    quitpage->home = InitButton(QP_HOME_HEIGHT, QP_HOME_WIDTH, QP_HOME_X, QP_HOME_Y, QP_HOME_IMG, QP_HOME_NAME, QP_HOME_IMG_ON_HOV, &qpHomeOnClick);
    quitpage->startGame = InitButton(QP_STARTGAME_HEIGHT, QP_STARTGAME_WIDTH, QP_STARTGAME_X, QP_STARTGAME_Y, QP_STARTGAME_IMG, QP_STARTGAME_NAME, QP_STARTGAME_IMG_ON_HOV, &qpStartOnClick);
    return quitpage;
}

void qpKontinueOnClick()
{
    PlayChunk(CHUNK_BEST);
    switch (app.quitpage->lastScene) {
    case StartScene:
        DrawStartPage(&app);
        break;
    case GameScene:
        DrawGamePage(&app);
        break;
    case OverScene:
        DrawOverPage(&app);
        break;
    default:
        break;
    }
}

void qpHomeOnClick()
{
    PlayChunk(CHUNK_IMPROVE_LEVEL);
    DrawStartPage(&app);
}

void qpQuitOnClick()
{
    PlayChunk(CHUNK_GOOD);
    DestroyWindow(&app);
    exit(EXIT_SUCCESS);
}
void qpStartOnClick()
{
    app.gamepage->isGodMode = 0;
    InitNewGame(&app);
}
void DrawQuitPage(App *app)
{
    app->quitpage->lastScene = app->curScene;
    app->curScene = QuitScene;
    changeBgColor(app, app->bgColor);
    LoadButton(app, app->quitpage->kontinue);
    LoadButton(app, app->quitpage->quit);
    LoadButton(app, app->quitpage->home);
    LoadButton(app, app->quitpage->startGame);
}
