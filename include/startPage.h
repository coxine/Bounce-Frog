#ifndef INCLUDE_STARTPAGE_H_
#define INCLUDE_STARTPAGE_H_

#define SP_TITLE_FILE "../static/img/Title.svg"
#define SP_TITLE_HEIGHT 200
#define SP_TITLE_WIDTH 400
#define SP_TITLE_NAME "StartPageTitle"
#define SP_TITLE_X 440
#define SP_TITLE_Y 100

#define SP_STARTGAME_HEIGHT 150
#define SP_STARTGAME_WIDTH 300
#define SP_STARTGAME_X 290
#define SP_STARTGAME_Y 400
#define SP_STARTGAME_IMG "../static/img/Start.svg"
#define SP_STARTGAME_IMG_ON_HOV "../static/img/Start_hov.svg"
#define SP_STARTGAME_NAME "StartGame"

#define SP_GODMODE_HEIGHT 150
#define SP_GODMODE_WIDTH 300
#define SP_GODMODE_X 690
#define SP_GODMODE_Y 400
#define SP_GODMODE_IMG "../static/img/GodMode.svg"
#define SP_GODMODE_IMG_ON_HOV "../static/img/GodMode_hov.svg"
#define SP_GODMODE_NAME "GodMode"

#include <common.h>

StartPage *InitStartPage(App *app);
void LoadStartPage(App *app, StartPage *startpage);
#endif