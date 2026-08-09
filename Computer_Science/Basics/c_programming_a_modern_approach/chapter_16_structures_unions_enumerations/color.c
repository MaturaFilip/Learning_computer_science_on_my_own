#include <stdio.h>
#include <stdbool.h>

typedef struct Color {
    int red;
    int green;
    int blue;
} Color;

Color make_color(int red, int green, int blue);
int check_col(int x);
bool equal_color(Color color1, Color color2);
int getRed(Color c);
Color brighter(Color c);
Color darker(Color c);

int main(void) {


    Color a = make_color(256, -1, 20);
    Color b = make_color(256, -1, 20);
    printf("%d\n", equal_color(a, b));

    return 0;
}

Color make_color(int red, int green, int blue) {
    Color x = {
        .red = check_col(red),
        .green = check_col(green),
        .blue = check_col(blue),
    };
    return x;
}

int check_col(int x) {
    if (x > 255) {
        return 255;
    } else if (x < 0) {
        return 0;
    } else {
        return x;
    }
}

int getRed(Color c) {
    return c.red;
}

bool equal_color(Color color1, Color color2) {
    if (color1.red == color2.red &&
        color1.green == color2.green &&
        color1.blue == color2.blue) {
            return true;
        } else {
            return false;
        }
}

Color brighter(Color c) {
    Color x;
    if (c.red == 0 && c.green == 0 && c.blue == 0) {
        x.red = x.green = x.blue = 3;
        return x;
    }

    if (c.red > 0 && c.red < 3) {
        c.red = 3;
    }
    if (c.green > 0 && c.green < 3) {
        c.green = 3;
    }
    if (c.blue > 0 && c.blue < 3) {
        c.blue = 3;
    }

    if ((c.red / 0.7) > 255) {
        x.red = 255;
    } else {
        x.red = c.red / 0.7;
    }
    if ((c.green / 0.7) > 255) {
        x.green = 255;
    } else {
        x.green = c.green / 0.7;
    }
    if ((c.blue / 0.7) > 255) {
        x.blue = 255;
    } else {
        x.blue = c.blue / 0.7;
    }
    return x;
}

Color darker(Color c) {
    Color x = {
        .red = c.red * 0.7,
        .green = c.green * 0.7,
        .blue = c.blue * 0.7,
    };
    return x;
}