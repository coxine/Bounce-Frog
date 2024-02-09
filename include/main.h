#ifndef INCLUDE_MAIN_H_
#define INCLUDE_MAIN_H_

// 窗口
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define START_X 100
#define START_Y 100
#define WINDOW_TITLE "青蛙跳跳"

#define MAX_SCORE_STR_LEN 50

#define FROG_HOP_DY 0.5
#define MAX_HOP_TIME 1056

#include <common.h>

// 解绑
#undef main

void InitApp();
void StartUp();

#endif