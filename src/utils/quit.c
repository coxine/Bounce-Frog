#include <utils/quit.h>

extern ObjectStyle window;

void Quit(App *app)
{
    changeBgColor(app->renderer, window.color);
    QuitPage *quitpage = InitQuitPage(app);
    LoadQuitPage(app, quitpage);

    // event
    SDL_Event event;
    while (app->curScene == QuitScene) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_MOUSEMOTION:
                if (isHover(quitpage->kontinue)) {
                    LoadImage(app, quitpage->kontinue->imgOnHover);
                } else {
                    LoadImage(app, quitpage->kontinue->img);
                }
                if (isHover(quitpage->quit)) {
                    LoadImage(app, quitpage->quit->imgOnHover);
                } else {
                    LoadImage(app, quitpage->quit->img);
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (isClick(quitpage->kontinue)) {
                    app->curScene = StartScene;
                    return;
                }
                if (isClick(quitpage->quit)) {
                    DestroyWindow(app);
                    exit(EXIT_SUCCESS);
                }
                break;
            default:
                break;
            }
        }
        SDL_Delay(2);
    }
}

QuitPage *InitQuitPage(App *app)
{
    app->curScene = QuitScene;
    QuitPage *quitpage = malloc(sizeof(QuitPage));
    if (quitpage == NULL) {
        puts("Fail to Init QuitPage");
        exit(EXIT_FAILURE);
    }
    quitpage->kontinue = InitButton(QP_CONTINUE_HEIGHT, QP_CONTINUE_WIDTH, QP_CONTINUE_X, QP_CONTINUE_Y, QP_CONTINUE_IMG, QP_CONTINUE_NAME, QP_CONTINUE_IMG_ON_HOV);
    quitpage->quit = InitButton(QP_QUIT_HEIGHT, QP_QUIT_WIDTH, QP_QUIT_X, QP_QUIT_Y, QP_QUIT_IMG, QP_QUIT_NAME, QP_QUIT_IMG_ON_HOV);
    return quitpage;
}

void LoadQuitPage(App *app, QuitPage *quitpage)
{
    LoadButton(app, quitpage->kontinue);
    LoadButton(app, quitpage->quit);
}

void DestroyWindow(App *app)
{
    SDL_FreeSurface(app->windowIcon);
    SDL_DestroyWindow(app->window);
    SDL_DestroyRenderer(app->renderer);
}