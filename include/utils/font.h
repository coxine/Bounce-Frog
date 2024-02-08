#ifndef INCLUDE_UTILS_FONT_H_
#define INCLUDE_UTILS_FONT_H_

#include <common.h>

Text *InitText(TTF_Font *fontFamily, SDL_Color fontColor, int x, int y, int fontSize, int fontStyle);
void Write(App *app, Text *text, char *content);
#endif