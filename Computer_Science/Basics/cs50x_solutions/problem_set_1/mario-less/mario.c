#include <stdio.h>
#include <cs50.h>

void print_hash(int spaces, int bricks);

int main(void) {
    /*
    Ask user how hight the pyramid should be and print it
    */

    int h;

    while(1) {
        h = get_int("Height: ");
        if (h <= 0) {continue;} else {break;}
    }

    for (int i = 0; i < h; i++) {
        int spaces = h - i;
        print_hash(spaces, i + 1);
    }
}

void print_hash(int spaces, int bricks) {
    for (int i = 1; i < spaces; i++) {
        printf(" ");
    }
    for(int i = 0; i < bricks; i++) {
        printf("#");
    }
    printf("\n");
}

