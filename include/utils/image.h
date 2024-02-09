#ifndef INCLUDE_UTILS_IMAGE_H_
#define INCLUDE_UTILS_IMAGE_H_

#include <common.h>

Image *InitImage(char *file, int height, int width, char *name, int x, int y);
void LoadImage(App *app, Image *img);
void UpdateImage(Image *img, char *file, int height, int width, char *name, int x, int y);
void DestroyImage(Image *img);
#endif