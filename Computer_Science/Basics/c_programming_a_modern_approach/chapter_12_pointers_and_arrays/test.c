#include <stdio.h>

int main(void) {
    int a[10], *p;
    int j = 5;
    int i = 0;
    a[0] = 9;
    printf("%d\n", a[0]);

    a[i++] = j;
    printf("%d\n", a[0]);
    printf("i = %d\n", i);
    return 0;
}