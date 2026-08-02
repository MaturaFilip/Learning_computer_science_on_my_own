#include <stdio.h>

#define MK_ID(n) i##n

int main(void) {
    int MK_ID(1);
    printf("%d\n", i1);
    i1 = 20;
    printf("%d\n", i1);

    return 0;
}