#include <stdio.h>


void find_two_largest(const int *a, int n, int *largest, int *second_largest);

int main(void) {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int largest, second_largest;
    find_two_largest(a, 10, &largest, &second_largest);
    printf("largest: %d, second largest: %d\n", largest, second_largest);
    return 0;
}

void find_two_largest(const int *a, int n, int *largest, int *second_largest) {
    *largest = *a;
    *second_largest = *a + 1;

    for (int *p = a; p < a + n; p++) {
        if (*p > *largest) {
            *second_largest = *largest;
            *largest = *p;
        }
        if (*p < *largest && *p > *second_largest) {
            *second_largest = *p;
        }
    }
}

