#ifndef SRC_CONFIG_ELEMENTSTYLE_H_
#define SRC_CONFIG_ELEMENTSTYLE_H_

typedef struct Color {
    int r;
    int g;
    int b;
    int a;
} color;

typedef struct ObjectStyle {
    color color;
} objectStyle;

extern const objectStyle windowStyle;
#endif