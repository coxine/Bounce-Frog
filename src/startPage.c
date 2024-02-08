#include <startPage.h>

extern const ObjectStyle window;

StartPage *InitStartPage()
{
    StartPage *startpage = malloc(sizeof(StartPage));
    if (startpage == NULL) {
        puts("Fail to Init StartPage");
        exit(EXIT_FAILURE);
    }
    startpage->startPageTitle = InitImage(SP_TITLE_FILE, SP_TITLE_HEIGHT, SP_TITLE_WIDTH, SP_TITLE_NAME, SP_TITLE_X, SP_TITLE_Y);
    startpage->startGame = InitButton(SP_STARTGAME_HEIGHT, SP_STARTGAME_WIDTH, SP_STARTGAME_X, SP_STARTGAME_Y, SP_STARTGAME_IMG, SP_STARTGAME_NAME, SP_STARTGAME_IMG_ON_HOV, NULL);
    startpage->godMode = InitButton(SP_GODMODE_HEIGHT, SP_GODMODE_WIDTH, SP_GODMODE_X, SP_GODMODE_Y, SP_GODMODE_IMG, SP_GODMODE_NAME, SP_GODMODE_IMG_ON_HOV, NULL);
    return startpage;
}

void DrawStartPage(App *app)
{
    app->curScene = StartScene;
    changeBgColor(app->renderer, window.color);
    LoadImage(app, app->startpage->startPageTitle);
    LoadButton(app, app->startpage->startGame);
    LoadButton(app, app->startpage->godMode);
}