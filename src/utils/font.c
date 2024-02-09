#include <utils/font.h>

Text *InitText(TTF_Font *fontFamily, SDL_Color fontColor, int x, int y, int fontSize, int fontStyle)
{
    Text *text = malloc(sizeof(Text));
    text->fontColor = fontColor;
    text->fontFamily = fontFamily;
    text->fontSize = fontSize;
    text->fontStyle = fontStyle;
    text->x = x;
    text->y = y;

    return text;
}

void LoadText(App *app, Text *text, char *content)
{
    text->content = malloc(strlen(content) + 1);
    strcpy(text->content, content);
    TTF_SetFontSize(text->fontFamily, text->fontSize);
    TTF_SetFontStyle(text->fontFamily, text->fontStyle);
    SDL_Surface *textSurface = TTF_RenderUTF8_Blended(text->fontFamily, text->content, text->fontColor);

    SDL_Rect *textRect = malloc(sizeof(SDL_Rect));
    textRect->x = text->x;
    textRect->y = text->y;

    // Render it
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(app->renderer, textSurface);
    SDL_QueryTexture(textTexture, NULL, NULL, &(textRect->w), &(textRect->h));
    text->width = textRect->w;
    text->height = textRect->h;
    SDL_RenderCopy(app->renderer, textTexture, NULL, textRect);

    // Kill what you've created
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    free(textRect);
}

void WriteText(App *app, Text *text, char *content)
{
    FillRect(app->bgColor, text->x, text->y, text->width, text->height);
    LoadText(app, text, content);
    SDL_RenderPresent(app->renderer);
}
