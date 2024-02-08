#include <pages/quitPage.h>

extern ObjectStyle window;

QuitPage *InitQuitPage()
{
    QuitPage *quitpage = malloc(sizeof(QuitPage));
    if (quitpage == NULL) {
        puts("Fail to Init QuitPage");
        exit(EXIT_FAILURE);
    }
    quitpage->kontinue = InitButton(QP_KONTINUE_HEIGHT, QP_KONTINUE_WIDTH, QP_KONTINUE_X, QP_KONTINUE_Y, QP_KONTINUE_IMG, QP_KONTINUE_NAME, QP_KONTINUE_IMG_ON_HOV, &kontinueOnClick);
    quitpage->quit = InitButton(QP_QUIT_HEIGHT, QP_QUIT_WIDTH, QP_QUIT_X, QP_QUIT_Y, QP_QUIT_IMG, QP_QUIT_NAME, QP_QUIT_IMG_ON_HOV, quitOnClick);
    return quitpage;
}

void kontinueOnClick()
{
    PlayChunk(CHUNK_GOOD);
    DrawStartPage(&app);
}

void quitOnClick()
{
    PlayChunk(CHUNK_GOOD);
    DestroyWindow(&app);
    exit(EXIT_SUCCESS);
}
void DrawQuitPage(App *app)
{
    app->curScene = QuitScene;
    changeBgColor(app->renderer, window.color);
    LoadButton(app, app->quitpage->kontinue);
    LoadButton(app, app->quitpage->quit);
}
