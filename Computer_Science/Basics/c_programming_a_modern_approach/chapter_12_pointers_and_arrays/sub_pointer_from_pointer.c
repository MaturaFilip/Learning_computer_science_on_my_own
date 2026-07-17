#include <stdio.h>

int main(void) {
    int a[10], *p, *q, i;

    p = &a[5];
    q = &a[1];

    // 4!!! INTEGER
    i = p - q;
    printf("%d\n", i);

    return 0;
}