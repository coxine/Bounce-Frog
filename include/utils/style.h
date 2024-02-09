#ifndef INCLUDE_UTILS_style_H_
#define INCLUDE_UTILS_style_H_

#include <common.h>

void LoadBgColor(App *app, SDL_Color bgColor);
void ChangeBgColor(App *app, SDL_Color bgColor);
void FillRect(SDL_Color bgColor, int x, int y, int width, int height);
#endif