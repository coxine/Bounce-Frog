#ifndef INCLUDE_UTILS_QUIT_H_
#define INCLUDE_UTILS_QUIT_H_

#define QP_CONTINUE_HEIGHT 150
#define QP_CONTINUE_WIDTH 300
#define QP_CONTINUE_X 290
#define QP_CONTINUE_Y 400
#define QP_CONTINUE_IMG "../static/img/Continue.svg"
#define QP_CONTINUE_IMG_ON_HOV "../static/img/Continue_hov.svg"
#define QP_CONTINUE_NAME "Continue"

#define QP_QUIT_HEIGHT 150
#define QP_QUIT_WIDTH 300
#define QP_QUIT_X 690
#define QP_QUIT_Y 400
#define QP_QUIT_IMG "../static/img/Quit.svg"
#define QP_QUIT_IMG_ON_HOV "../static/img/Quit_hov.svg"
#define QP_QUIT_NAME "Quit"

#include <common.h>
#include <utils/button.h>

QuitPage *InitQuitPage();
void DrawQuitPage(App *app);
void DestroyWindow(App *app);

#endif