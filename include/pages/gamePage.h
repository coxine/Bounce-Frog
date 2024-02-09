#ifndef INCLUDE_PAGES_GAMEPAGE_H_
#define INCLUDE_PAGES_GAMEPAGE_H_

#include <common.h>

#define MAX_FLORR_NUM 260817

#define GP_FROG_HEIGHT 50
#define GP_FROG_WIDTH 50
#define GP_FROG_X 615
#define GP_FROG_Y 45
#define GP_FROG_NAME "frog"
#define GP_FROG_IMG "../static/img/Frog.png"

#define GP_CURSCORE_X 1000
#define GP_CURSCORE_Y 100
#define GP_CURSCORE_FONTSIZE 30
#define GP_CURSCORE_FONTSTYLE TTF_STYLE_NORMAL

#define GP_MAXSCORE_X 1000
#define GP_MAXSCORE_Y 140
#define GP_MAXSCORE_FONTSIZE 30
#define GP_MAXSCORE_FONTSTYLE TTF_STYLE_NORMAL

GamePage *InitGamePage();
void DrawGamePage(App *app);
void InitNewGame(App *app);
// bool isFrogOnFlorr(Obj frog, int florrID);
#endif