#ifndef INCLUDE_UTILS_BUTTON_H_
#define INCLUDE_UTILS_BUTTON_H_

#include <common.h>
#include <utils/image.h>

Button *InitButton(int height, int width, int x, int y, char *file, char *name, char *hovFile);
void LoadButton(App *app, Button *button);
bool isHover(Button *button);
bool isClick(Button *button);
void UpdateButton(App *app, Button *button);
void DestroyButton(Button *button);

#endif