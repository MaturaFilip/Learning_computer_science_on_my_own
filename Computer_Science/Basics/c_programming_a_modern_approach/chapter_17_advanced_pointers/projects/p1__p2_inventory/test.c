#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *blabla = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        blabla[i] = 0;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d\n", blabla[i]);
    }
    return 0;
}