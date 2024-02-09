#ifndef INCLUDE_PAGES_OVERPAGE_H_
#define INCLUDE_PAGES_OVERPAGE_H_

#include <common.h>

#define OP_HOME_HEIGHT 150
#define OP_HOME_WIDTH 300
#define OP_HOME_X 290
#define OP_HOME_Y 400
#define OP_HOME_IMG "../static/img/Home.png"
#define OP_HOME_IMG_ON_HOV "../static/img/Home_hov.png"
#define OP_HOME_NAME "Home"

#define OP_QUIT_HEIGHT 150
#define OP_QUIT_WIDTH 300
#define OP_QUIT_X 690
#define OP_QUIT_Y 400
#define OP_QUIT_IMG "../static/img/Quit.png"
#define OP_QUIT_IMG_ON_HOV "../static/img/Quit_hov.png"
#define OP_QUIT_NAME "Quit"

#define OP_CURSCORE_X 290
#define OP_CURSCORE_Y 100
#define OP_CURSCORE_FONTSIZE 80
#define OP_CURSCORE_FONTSTYLE TTF_STYLE_NORMAL

#define OP_MAXSCORE_X 290
#define OP_MAXSCORE_Y 200
#define OP_MAXSCORE_FONTSIZE 80
#define OP_MAXSCORE_FONTSTYLE TTF_STYLE_NORMAL

OverPage *InitOverPage();
void DrawOverPage(App *app);
void opHomeOnClick();
void opQuitOnClick();

#endif