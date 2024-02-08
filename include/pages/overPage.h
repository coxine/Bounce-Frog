#ifndef INCLUDE_PAGES_OVERPAGE_H_
#define INCLUDE_PAGES_OVERPAGE_H_

#include <common.h>

#define OP_HOME_HEIGHT 150
#define OP_HOME_WIDTH 300
#define OP_HOME_X 290
#define OP_HOME_Y 400
#define OP_HOME_IMG "../static/img/Home.svg"
#define OP_HOME_IMG_ON_HOV "../static/img/Home_hov.svg"
#define OP_HOME_NAME "Homoe"

#define OP_QUIT_HEIGHT 150
#define OP_QUIT_WIDTH 300
#define OP_QUIT_X 690
#define OP_QUIT_Y 400
#define OP_QUIT_IMG "../static/img/Quit.svg"
#define OP_QUIT_IMG_ON_HOV "../static/img/Quit_hov.svg"
#define OP_QUIT_NAME "Quit"

OverPage *InitOverPage();
void DrawOverPage(App *app);
void opHomeOnClick();
void opQuitOnClick();

#endif