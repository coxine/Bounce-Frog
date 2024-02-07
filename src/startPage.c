#include <startPage.h>
Image *startPageTitle;
Button *startGame;
Button *godMode;

void DisplayStartPage(App *app)
{
    app->curScene = 1;
    // Title
    startPageTitle = InitImage(SP_TITLE_FILE, SP_TITLE_HEIGHT, SP_TITLE_WIDTH, SP_TITLE_NAME, SP_TITLE_X, SP_TITLE_Y);
    LoadImage(app, startPageTitle);
    // Start
    startGame = InitButton(SP_STARTGAME_HEIGHT, SP_STARTGAME_WIDTH, SP_STARTGAME_X, SP_STARTGAME_Y, SP_STARTGAME_IMG, SP_STARTGAME_NAME);
    LoadButton(app, startGame);
    // godMode
    godMode = InitButton(SP_GODMODE_HEIGHT, SP_GODMODE_WIDTH, SP_GODMODE_X, SP_GODMODE_Y, SP_GODMODE_IMG, SP_GODMODE_NAME);
    LoadButton(app, godMode);
}

void DestroyStartPage()
{
    free(startPageTitle);
    DestroyButton(startGame);
    DestroyButton(godMode);
}