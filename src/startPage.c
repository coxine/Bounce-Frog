#include <startPage.h>

StartPage *InitStartPage(App *app)
{
    app->curScene = StartScene;
    StartPage *startpage = malloc(sizeof(StartPage));
    if (startpage == NULL) {
        puts("Fail to Init StartPage");
        exit(EXIT_FAILURE);
    }
    startpage->startPageTitle = InitImage(SP_TITLE_FILE, SP_TITLE_HEIGHT, SP_TITLE_WIDTH, SP_TITLE_NAME, SP_TITLE_X, SP_TITLE_Y);
    startpage->startGame = InitButton(SP_STARTGAME_HEIGHT, SP_STARTGAME_WIDTH, SP_STARTGAME_X, SP_STARTGAME_Y, SP_STARTGAME_IMG, SP_STARTGAME_NAME, SP_STARTGAME_IMG_ON_HOV);
    startpage->godMode = InitButton(SP_GODMODE_HEIGHT, SP_GODMODE_WIDTH, SP_GODMODE_X, SP_GODMODE_Y, SP_GODMODE_IMG, SP_GODMODE_NAME, SP_GODMODE_IMG_ON_HOV);
    return startpage;
}

void LoadStartPage(App *app, StartPage *startpage)
{
    LoadImage(app, startpage->startPageTitle);
    LoadButton(app, startpage->startGame);
    LoadButton(app, startpage->godMode);

    // event
    SDL_Event event;
    while (app->curScene == StartScene) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                Quit(app);
                puts("222");
                break;
            case SDL_MOUSEMOTION:
                if (isHover(startpage->startGame)) {
                    LoadImage(app, startpage->startGame->imgOnHover);
                } else {
                    LoadImage(app, startpage->startGame->img);
                }
                if (isHover(startpage->godMode)) {
                    LoadImage(app, startpage->godMode->imgOnHover);
                } else {
                    LoadImage(app, startpage->godMode->img);
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (isClick(startpage->startGame)) {
                    puts("111");
                }
                if (isClick(startpage->godMode)) {
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