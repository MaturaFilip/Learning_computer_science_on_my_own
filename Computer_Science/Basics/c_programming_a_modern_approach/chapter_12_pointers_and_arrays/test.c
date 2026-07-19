#include <stdio.h>


void store_zeros(int *a, int n);

int main(void) {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    store_zeros(a, 10);

    for (int i = 0; i < 10; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}

void store_zeros(int *a, int n) {
    int *p;

    for (p = a; p < a + n; p++) {
        *p = 0;
    }
}