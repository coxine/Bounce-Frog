#ifndef INCLUDE_UTILS_BUTTON_H_
#define INCLUDE_UTILS_BUTTON_H_

#include <utils/image.h>

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

Button *InitButton(int height, int width, int x, int y, char *file, char *name);
void LoadButton(App *app, Button *button);
bool isHover(Button *button);
bool isClick(Button *button);
void UpdateButton(App *app, Button *button);
void DestroyButton(Button *button);

#endif