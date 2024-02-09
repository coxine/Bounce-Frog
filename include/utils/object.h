#ifndef INCLUDE_UTILS_OBJECT_H_
#define INCLUDE_UTILS_OBJECT_H_

#include <common.h>

bool isCollide(Obj *a, Obj *b);
void LoadObject(App *app, Obj *a);
void ResumeBgColor(App *app, const Obj *a, SDL_Color bgColor);
void Move(App *app, Obj *a, Speed InitX, Speed InitY, Speed dx, Speed dy, int times);

#endif