#ifndef INCLUDE_UTILS_TYPES_H_
#define INCLUDE_UTILS_TYPES_H_

// 离谱... 分开放会产生奇奇怪怪的冲突

#include <common.h>

enum scene {
    StartScene = 1, // 主页
    GameScene,      // 游戏界面
    OverScene,      // 游戏结束界面
    QuitScene       // 退出界面
};

typedef struct {
    int r;
    int g;
    int b;
    int a;
} Color;

typedef struct {
    Color color;
} ObjectStyle;

typedef struct {
    int height;
    int width;
    int x;
    int y;
    char *name;
    char *file;
} Image;

typedef struct {
    Image *img;
    Image *imgOnHover;
    char *name;
    void (*onClick)(void);
    int height;
    int width;
    int x;
    int y;
} Button;

typedef struct {
    Image *startPageTitle;
    Button *startGame;
    Button *godMode;
} StartPage;

typedef struct {
    Button *kontinue;
    Button *quit;
} QuitPage;

typedef struct {
    Button *home;
    Button *quit;
} OverPage;

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *windowIcon;
    enum scene curScene;
    int maxScore;
    int curScore;
    SDL_Event *event;
    StartPage *startpage;
    QuitPage *quitpage;
    OverPage *overpage;
} App;
#endif