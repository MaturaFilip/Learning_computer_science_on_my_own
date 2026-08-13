#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int * restrict p;
    int * restrict q;

    p = malloc(sizeof(int));
    *p = 10;

    printf("%d\n", *p);

    q = p;
    printf("%d\n", *q);

    // *q = 0;      /* Causes undefined behavior */
    return 0;
}