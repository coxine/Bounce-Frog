#include <utils/button.h>

Button *InitButton(int height, int width, int x, int y, char *file, char *name, char *hovFile, void (*onClick)(void))
{
    Button *button = malloc(sizeof(Button));
    button->img = malloc(sizeof(Image));
    button->imgOnHover = malloc(sizeof(Image));

    button->img->file = malloc(sizeof(char) * (strlen(file) + 1));
    button->img->name = malloc(sizeof(char) * (strlen(name) + 1));
    button->imgOnHover->file = malloc(sizeof(char) * (strlen(hovFile) + 1));
    button->imgOnHover->name = malloc(sizeof(char) * (strlen(name) + 1));
    button->name = malloc(sizeof(char) * (strlen(name) + 1));
    button->height = height;
    button->width = width;
    button->x = x;
    button->y = y;
    strcpy(button->img->file, file);
    strcpy(button->img->name, name);
    strcpy(button->imgOnHover->file, hovFile);
    strcpy(button->imgOnHover->name, name);
    strcpy(button->name, name);
    button->onClick = onClick;
    return button;
}

void LoadButton(App *app, Button *button)
{
    button->img->height = button->height;
    button->img->width = button->width;
    button->img->x = button->x;
    button->img->y = button->y;
    button->imgOnHover->height = button->height;
    button->imgOnHover->width = button->width;
    button->imgOnHover->x = button->x;
    button->imgOnHover->y = button->y;
    LoadImage(app, button->img);
}

bool isHover(Button *button)
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    if (mouseX >= button->x && mouseX <= button->x + button->width && mouseY >= button->y && mouseY <= button->y + button->height) {
        return true;
    }
    return false;
}

bool isClick(Button *button)
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    if (mouseX >= button->x && mouseX <= button->x + button->width && mouseY >= button->y && mouseY <= button->y + button->height) {
        return true;
    }
    return false;
}

void UpdateButton(App *app, Button *button)
{
    if (isHover(button)) {
        LoadImage(app, button->imgOnHover);
    } else {
        LoadImage(app, button->img);
    }
}

void DoButton(Button *button)
{
    if (isClick(button)) {
        if (button->onClick != NULL) {
            button->onClick();
        }
    }
}

void DestroyButton(Button *button)
{
    free(button->img);
    free(button->imgOnHover);
    free(button);
}
