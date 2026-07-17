#include <stdio.h>
#define N 10

int main(void) {
    int sum, *p;

    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    sum = 0;
    for (p = &a[0]; p < &a[N]; p++) {
        sum += *p;
    }

    printf("sum: %d\n", sum);
    return 0;
}