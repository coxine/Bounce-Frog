#include <pages/overPage.h>

OverPage *InitOverPage()
{
    OverPage *overpage = malloc(sizeof(OverPage));
    if (overpage == NULL) {
        puts("Fail to Init OverPage");
        exit(EXIT_FAILURE);
    }

    overpage->curScoreStr = malloc(sizeof(char) * MAX_SCORE_STR_LEN);
    overpage->maxScoreStr = malloc(sizeof(char) * MAX_SCORE_STR_LEN);
    // TODO : Init CurScore MaxScore
    overpage->curScore = InitText(app.font, app.fontColor, OP_CURSCORE_X, OP_CURSCORE_Y, OP_CURSCORE_FONTSIZE, OP_CURSCORE_FONTSTYLE);
    overpage->maxScore = InitText(app.font, app.fontColor, OP_MAXSCORE_X, OP_MAXSCORE_Y, OP_MAXSCORE_FONTSIZE, OP_MAXSCORE_FONTSTYLE);
    overpage->home = InitButton(OP_HOME_HEIGHT, OP_HOME_WIDTH, OP_HOME_X, OP_HOME_Y, OP_HOME_IMG, OP_HOME_NAME, OP_HOME_IMG_ON_HOV, &opHomeOnClick);
    overpage->quit = InitButton(OP_QUIT_HEIGHT, OP_QUIT_WIDTH, OP_QUIT_X, OP_QUIT_Y, OP_QUIT_IMG, OP_QUIT_NAME, OP_QUIT_IMG_ON_HOV, &opQuitOnClick);
    return overpage;
}

void DrawOverPage(App *app)
{
    app->curScene = OverScene;

    changeBgColor(app, app->bgColor);
    sprintf(app->overpage->curScoreStr, "Score: %d", app->curScore);
    sprintf(app->overpage->maxScoreStr, "MaxScore: %d", app->maxScore);
    Write(app, app->overpage->curScore, app->overpage->curScoreStr);
    Write(app, app->overpage->maxScore, app->overpage->maxScoreStr);
    LoadButton(app, app->overpage->home);
    LoadButton(app, app->overpage->quit);
}

void opHomeOnClick()
{
    DrawStartPage(&app);
}

void opQuitOnClick()
{
    PlayChunk(CHUNK_GOOD);
    DestroyWindow(&app);
    exit(EXIT_SUCCESS);
}