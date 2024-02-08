#ifndef INCLUDE_MAIN_H_
#define INCLUDE_MAIN_H_

// 窗口
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define START_X 100
#define START_Y 100
#define WINDOW_TITLE "青蛙跳跳"

#include <common.h>

// 解绑
#undef main

void InitApp();
void StartUp();

#endif