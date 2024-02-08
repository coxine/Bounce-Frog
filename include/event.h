#ifndef INCLUDE_EVENT_H_
#define INCLUDE_EVENT_H_

#include <common.h>

void InitEvent(App *app);
void DoEvent(App *app);
void StartSceneEvent(App *app);
void GameSceneEvent(App *app);
void OverSceneEvent(App *app);
void QuitSceneEvent(App *app);
Uint32 GetKeyPressTime(App *app, SDL_Scancode scancode);

#endif