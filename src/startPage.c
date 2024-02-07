#include <startPage.h>
Image StartPageTitle = {
    .file = "../static/img/Title.svg",
    .height = 200,
    .width = 400,
    .name = "StartPageTitle",
    .x = 440,
    .y = 100,
};
void DisplayStartPage(App *app)
{
    LoadImage(app, &StartPageTitle);
}