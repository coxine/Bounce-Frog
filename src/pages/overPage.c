#include <pages/overPage.h>

extern ObjectStyle window;

OverPage *InitOverPage()
{
    OverPage *overpage = malloc(sizeof(OverPage));
    if (overpage == NULL) {
        puts("Fail to Init OverPage");
        exit(EXIT_FAILURE);
    }
    overpage->home = InitButton(OP_HOME_HEIGHT, OP_HOME_WIDTH, OP_HOME_X, OP_HOME_Y, OP_HOME_IMG, OP_HOME_NAME, OP_HOME_IMG_ON_HOV, &opHomeOnClick);
    overpage->quit = InitButton(OP_QUIT_HEIGHT, OP_QUIT_WIDTH, OP_QUIT_X, OP_QUIT_Y, OP_QUIT_IMG, OP_QUIT_NAME, OP_QUIT_IMG_ON_HOV, &opQuitOnClick);
    return overpage;
}

void DrawOverPage(App *app)
{
    app->curScene = OverScene;
    changeBgColor(app->renderer, window.color);
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