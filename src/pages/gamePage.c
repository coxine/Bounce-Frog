#include <pages/gamePage.h>

GamePage *InitGamePage()
{
    GamePage *gamepage = malloc(sizeof(GamePage));
    if (gamepage == NULL) {
        puts("Fail to Init GamePage");
        exit(EXIT_FAILURE);
    }

    gamepage->frog.image = InitImage(GP_FROG_IMG, GP_FROG_HEIGHT, GP_FROG_WIDTH, GP_FROG_NAME, GP_FROG_X, GP_FROG_Y);
    gamepage->frog.speedX = 0;
    gamepage->frog.speedY = 0;

    gamepage->curFlorr = 1;
    gamepage->minFlorr = 1;
    gamepage->maxFlorr = 1;
    gamepage->florr = malloc(sizeof(Obj) * MAX_FLORR_NUM);

    gamepage->curScoreStr = malloc(sizeof(char) * MAX_SCORE_STR_LEN);
    gamepage->maxScoreStr = malloc(sizeof(char) * MAX_SCORE_STR_LEN);

    gamepage->curScore = InitText(app.font, app.fontColor, GP_CURSCORE_X, GP_CURSCORE_Y, GP_CURSCORE_FONTSIZE, GP_CURSCORE_FONTSTYLE);
    gamepage->maxScore = InitText(app.font, app.fontColor, GP_MAXSCORE_X, GP_MAXSCORE_Y, GP_MAXSCORE_FONTSIZE, GP_MAXSCORE_FONTSTYLE);
    return gamepage;
}

void DrawGamePage(App *app)
{
    app->curScene = GameScene;

    changeBgColor(app, app->bgColor);
    sprintf(app->gamepage->curScoreStr, "Score: %d", app->curScore);
    sprintf(app->gamepage->maxScoreStr, "MaxScore: %d", app->maxScore);
    Write(app, app->gamepage->curScore, app->gamepage->curScoreStr);
    Write(app, app->gamepage->maxScore, app->gamepage->maxScoreStr);

    LoadObject(app, &(app->gamepage->frog));
}

void InitNewGame(App *app)
{
    UpdateImage(app->gamepage->frog.image, GP_FROG_IMG, GP_FROG_HEIGHT, GP_FROG_WIDTH, GP_FROG_NAME, GP_FROG_X, GP_FROG_Y);
    app->gamepage->frog.speedX = 0;
    app->gamepage->frog.speedY = 0;

    app->gamepage->curFlorr = 1;
    app->gamepage->minFlorr = 1;
    app->gamepage->maxFlorr = 1;
    free(app->gamepage->florr);
    app->gamepage->florr = malloc(sizeof(Obj) * MAX_FLORR_NUM);
    app->curScore = 0;
    DrawGamePage(app);
}
