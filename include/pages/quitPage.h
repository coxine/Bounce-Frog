#ifndef INCLUDE_PAGES_QUITPAGE_H_
#define INCLUDE_PAGES_QUITPAGE_H_

#include <common.h>

#define QP_KONTINUE_HEIGHT 150
#define QP_KONTINUE_WIDTH 300
#define QP_KONTINUE_X 290
#define QP_KONTINUE_Y 200
#define QP_KONTINUE_IMG "../static/img/Kontinue.png"
#define QP_KONTINUE_IMG_ON_HOV "../static/img/Kontinue_hov.png"
#define QP_KONTINUE_NAME "Kontinue"

#define QP_STARTGAME_HEIGHT 150
#define QP_STARTGAME_WIDTH 300
#define QP_STARTGAME_X 690
#define QP_STARTGAME_Y 200
#define QP_STARTGAME_IMG "../static/img/Start.png"
#define QP_STARTGAME_IMG_ON_HOV "../static/img/Start_hov.png"
#define QP_STARTGAME_NAME "Start"

#define QP_HOME_HEIGHT 150
#define QP_HOME_WIDTH 300
#define QP_HOME_X 290
#define QP_HOME_Y 370
#define QP_HOME_IMG "../static/img/Home.png"
#define QP_HOME_IMG_ON_HOV "../static/img/Home_hov.png"
#define QP_HOME_NAME "Home"

#define QP_QUIT_HEIGHT 150
#define QP_QUIT_WIDTH 300
#define QP_QUIT_X 690
#define QP_QUIT_Y 370
#define QP_QUIT_IMG "../static/img/Quit.png"
#define QP_QUIT_IMG_ON_HOV "../static/img/Quit_hov.png"
#define QP_QUIT_NAME "Quit"

QuitPage *InitQuitPage();
void DrawQuitPage(App *app);
void qpKontinueOnClick();
void qpQuitOnClick();
void qpHomeOnClick();
void qpStartOnClick();

#endif