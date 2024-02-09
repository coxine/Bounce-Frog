#ifndef INCLUDE_PAGES_GAMEPAGE_H_
#define INCLUDE_PAGES_GAMEPAGE_H_

#include <common.h>

#define MAX_FLORR_NUM 260817

#define GP_FROG_HEIGHT 100
#define GP_FROG_WIDTH 100
#define GP_FROG_X 590
#define GP_FROG_Y 360
#define GP_FROG_NAME "frog"
#define GP_FROG_IMG "../static/img/Frog.png"
#define FROG_HOP_DY 0.5
#define MAX_HOP_TIME 640

#define GP_CURSCORE_X 100
#define GP_CURSCORE_Y 100
#define GP_CURSCORE_FONTSIZE 30
#define GP_CURSCORE_FONTSTYLE TTF_STYLE_NORMAL

#define GP_MAXSCORE_X 100
#define GP_MAXSCORE_Y 140
#define GP_MAXSCORE_FONTSIZE 30
#define GP_MAXSCORE_FONTSTYLE TTF_STYLE_NORMAL

#define GP_FLOWER_IMG "../static/img/Flower.png"
#define GP_LEAF_IMG "../static/img/Leaf.png"
#define GP_IMG_HEIGHT 200
#define GP_IMG_WIDTH 200
#define GP_IMG_X_FIRST 540
#define GP_IMG_Y_FIRST 350
#define GP_FLORR_SPEED_X -16
#define GP_FLORR_SPEED_Y 8

GamePage *InitGamePage();
void DrawGamePage(App *app);
void InitNewGame(App *app);
void DrawScore(App *app);
void InitFlorr(int florrID);
bool CheckObjInWindow(Obj *obj);
void MoveFlorrAndFrog(App *app, int frogHopTime, int minFlorr, int maxFlorr);
void DestroyFlorr(App *app);
#endif