#ifndef INCLUDE_EVENT_H_
#define INCLUDE_EVENT_H_

#include <common.h>

void InitEvent(App *app);
void DoEvent(App *app);
void StartSceneEvent(App *app);
void QuitSceneEvent(App *app);

#endif