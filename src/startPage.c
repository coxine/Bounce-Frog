#include <startPage.h>
Image *startPageTitle;
Button *startGame;
Button *godMode;

void DisplayStartPage(App *app)
{
    // Load
    app->curScene = 1;

    startPageTitle = InitImage(SP_TITLE_FILE, SP_TITLE_HEIGHT, SP_TITLE_WIDTH, SP_TITLE_NAME, SP_TITLE_X, SP_TITLE_Y);
    LoadImage(app, startPageTitle);

    startGame = InitButton(SP_STARTGAME_HEIGHT, SP_STARTGAME_WIDTH, SP_STARTGAME_X, SP_STARTGAME_Y, SP_STARTGAME_IMG, SP_STARTGAME_NAME, SP_STARTGAME_IMG_ON_HOV);
    LoadButton(app, startGame);

    godMode = InitButton(SP_GODMODE_HEIGHT, SP_GODMODE_WIDTH, SP_GODMODE_X, SP_GODMODE_Y, SP_GODMODE_IMG, SP_GODMODE_NAME, SP_GODMODE_IMG_ON_HOV);
    LoadButton(app, godMode);

    // event
    SDL_Event event;
    while (app->curScene == 1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                Quit(app);
                exit(EXIT_SUCCESS);
                break;
            case SDL_MOUSEMOTION:
                if (isHover(startGame)) {
                    LoadImage(app, startGame->imgOnHover);
                } else {
                    LoadImage(app, startGame->img);
                }
                if (isHover(godMode)) {
                    LoadImage(app, godMode->imgOnHover);
                } else {
                    LoadImage(app, godMode->img);
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (isClick(startGame)) {
                    puts("111");
                }
                if (isClick(godMode)) {
                    puts("222");
                }
                break;
            default:
                break;
            }
        }
        SDL_Delay(2);
    }
}

void DestroyStartPage()
{
    free(startPageTitle);
    DestroyButton(startGame);
    DestroyButton(godMode);
}