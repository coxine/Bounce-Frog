#include <utils/object.h>

bool isCollide(Obj *a, Obj *b)
{
    int aCenterX = a->image->x + a->image->width / 2;
    int aBottomY = a->image->y + a->image->height;

    int bLeftX = b->image->x;
    int bRightX = b->image->x + b->image->width;
    int bTopY = b->image->y;
    int bBottomY = b->image->y + b->image->height;

    // 判断物体 A 是否能站在 B 上，即 A 的中心的 x 坐标在 B 的 x 坐标范围内，A 的底部在 B 的 y 坐标范围内
    if (aCenterX >= bLeftX && aCenterX <= bRightX && aBottomY >= bTopY && aBottomY <= bBottomY) {
        return true;
    } else {
        return false;
    }
}

bool isCenter(Obj *a, Obj *b)
{
    int aCenterX = a->image->x + a->image->width / 2;
    int aCenterY = a->image->y + a->image->height / 2;

    int bCenterX = b->image->x + b->image->width / 2;
    int bCenterY = b->image->y + b->image->height / 2;

    // 判断两个物体的中心横纵坐标是否相差在10以内
    if (abs(aCenterX - bCenterX) <= 20 && abs(aCenterY - bCenterY) <= 20) {
        return true;
    } else {
        return false;
    }
}

void LoadObject(App *app, Obj *a)
{
    UpdateImage(a->image, a->image->file, a->image->height, a->image->width, a->image->name, a->image->x, a->image->y);
    DrawImage(app, a->image);
}

void ResumeBgColor(App *app, const Obj *a, SDL_Color bgColor)
{
    if (a == NULL || a->image == NULL)
        return;
    SDL_Rect rect;
    rect.x = a->image->x;
    rect.y = a->image->y;
    rect.w = a->image->width;
    rect.h = a->image->height;

    SDL_SetRenderDrawColor(app->renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
    SDL_RenderFillRect(app->renderer, &rect);
}

void Move(App *app, Obj *a, Speed InitX, Speed InitY, Speed dx, Speed dy, int times, int delay)
{
    if (a == NULL || a->image == NULL || times <= 0)
        return;

    Speed vx = InitX;
    Speed vy = InitY;

    for (int i = 0; i < times; i++) {
        // ResumeBgColor(app, a, app->bgColor);
        int newX = a->image->x + (int)(vx);
        int newY = a->image->y + (int)(vy);

        a->image->x = newX;
        a->image->y = newY;
        LoadImage(app, a->image);

        // 更新速度
        vx += dx;
        vy += dy;
        SDL_Delay(delay);
    }
}
