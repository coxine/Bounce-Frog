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

typedef double Speed;

typedef struct {
    int height;
    int width;
    int x;
    int y;
    char *name;
    char *file;
} Image;

typedef struct {
    Image *image;
    Speed speedX;
    Speed speedY;
} Obj;

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
    char *content;
    TTF_Font *fontFamily;
    SDL_Color fontColor;
    int x;
    int y;
    int fontSize;
    int fontStyle;
} Text;

typedef struct {
    Image *startPageTitle;
    Button *startGame;
    Button *godMode;
} StartPage;

typedef struct {
    Button *kontinue;
    Button *quit;
    enum scene lastScene;
} QuitPage;

typedef struct {
    bool isGodMode;
    int curFlorr;
    int minFlorr; // 可见区域的花朵的最小值
    int maxFlorr; // 可见区域花朵的最大值
    Obj frog;
    Obj *florr;

    char *curScoreStr;
    char *maxScoreStr;
    Text *curScore;
    Text *maxScore;

    Text *broadcast;
} GamePage;

typedef struct {
    Button *home;
    Button *quit;
    char *curScoreStr;
    char *maxScoreStr;
    Text *curScore;
    Text *maxScore;
} OverPage;

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *windowIcon;
    enum scene curScene;
    int maxScore;
    int curScore;

    SDL_Event *event;
    bool keyPress[SDL_NUM_SCANCODES];
    Uint32 keyTimestamp[SDL_NUM_SCANCODES][2];

    TTF_Font *font;
    SDL_Color fontColor;

    StartPage *startpage;
    QuitPage *quitpage;
    OverPage *overpage;
    GamePage *gamepage;
    SDL_Color bgColor;
} App;
#endif