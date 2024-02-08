#ifndef INCLUDE_PAGES_QUITPAGE_H_
#define INCLUDE_PAGES_QUITPAGE_H_

#include <common.h>

#define QP_KONTINUE_HEIGHT 150
#define QP_KONTINUE_WIDTH 300
#define QP_KONTINUE_X 290
#define QP_KONTINUE_Y 300
#define QP_KONTINUE_IMG "../static/img/Kontinue.svg"
#define QP_KONTINUE_IMG_ON_HOV "../static/img/Kontinue_hov.svg"
#define QP_KONTINUE_NAME "Kontinue"

#define QP_QUIT_HEIGHT 150
#define QP_QUIT_WIDTH 300
#define QP_QUIT_X 690
#define QP_QUIT_Y 300
#define QP_QUIT_IMG "../static/img/Quit.svg"
#define QP_QUIT_IMG_ON_HOV "../static/img/Quit_hov.svg"
#define QP_QUIT_NAME "Quit"

QuitPage *InitQuitPage();
void DrawQuitPage(App *app);
void qpKontinueOnClick();
void qpQuitOnClick();

#endif