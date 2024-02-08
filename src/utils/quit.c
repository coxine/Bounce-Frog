#include <utils/quit.h>

extern ObjectStyle window;

QuitPage *InitQuitPage()
{
    QuitPage *quitpage = malloc(sizeof(QuitPage));
    if (quitpage == NULL) {
        puts("Fail to Init QuitPage");
        exit(EXIT_FAILURE);
    }
    quitpage->kontinue = InitButton(QP_CONTINUE_HEIGHT, QP_CONTINUE_WIDTH, QP_CONTINUE_X, QP_CONTINUE_Y, QP_CONTINUE_IMG, QP_CONTINUE_NAME, QP_CONTINUE_IMG_ON_HOV);
    quitpage->quit = InitButton(QP_QUIT_HEIGHT, QP_QUIT_WIDTH, QP_QUIT_X, QP_QUIT_Y, QP_QUIT_IMG, QP_QUIT_NAME, QP_QUIT_IMG_ON_HOV);
    return quitpage;
}

void DrawQuitPage(App *app)
{
    app->curScene = QuitScene;
    changeBgColor(app->renderer, window.color);
    LoadButton(app, app->quitpage->kontinue);
    LoadButton(app, app->quitpage->quit);
}

void DestroyWindow(App *app)
{
    SDL_FreeSurface(app->windowIcon);
    SDL_DestroyWindow(app->window);
    SDL_DestroyRenderer(app->renderer);
}