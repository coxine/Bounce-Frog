#ifndef INCLUDE_MAIN_H_
#define INCLUDE_MAIN_H_

// 窗口
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define START_X 100
#define START_Y 100
#define WINDOW_TITLE "青蛙跳跳"

#include <common.h>
#include <startPage.h>

// 解绑
#undef main

extern const objectStyle window;

static void InitApp();
static void StartUp();

#endif