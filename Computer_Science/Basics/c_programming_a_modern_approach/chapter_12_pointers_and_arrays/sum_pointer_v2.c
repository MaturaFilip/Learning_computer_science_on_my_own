#include <stdio.h>
#define N 10

int main(void) {
    int sum, *p;

    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    p = &a[0];
    while (p < &a[N]) {
        // add number to sum and then increment p (p++ = postfix version, ++p = prefix version)
        sum += *p++;
    }

    printf("sum: %d\n", sum);
    return 0;
}