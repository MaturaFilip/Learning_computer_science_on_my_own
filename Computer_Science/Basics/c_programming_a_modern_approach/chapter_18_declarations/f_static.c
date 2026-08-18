#include <stdio.h>

int f(int i);

int main(void) {
    int x = f(10);
    printf("first call: %d\n", x);

    f(10);
    f(10);
    f(10);
    f(10);
    int y = f(10);
    printf("last call: %d\n", y);
    return 0;
}

int f(int i) {
    static int j = 0;
    printf("%d\n", j);
    return i * j++;
}