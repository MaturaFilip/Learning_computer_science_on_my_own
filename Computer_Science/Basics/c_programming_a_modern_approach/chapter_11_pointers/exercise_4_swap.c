#include <stdio.h>

void swap(int *p, int *q);

int main(void) {
    int i = 1;
    int j = 2;

    printf("Before swap: i = %d, j = %d\n", i, j);

    swap(&i, &j);
    printf("After swap: i = %d, j = %d\n", i, j);

    return 0;
}

void swap (int *p, int *q) {
    int temp = *q;
    *q = *p;
    *p = temp;
}