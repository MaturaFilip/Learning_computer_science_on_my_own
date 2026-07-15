#include <stdio.h>

void find_two_largest(int n, int a[n], int *largest, int *second_largest);

int main(void) {
    int largest;
    int second_largest;

    int n = 5;
    int a[5] = {5, 2, 3, 4, 1};

    find_two_largest(n, a, &largest, &second_largest);
    printf("Largest: %d, second largest: %d\n", largest, second_largest);

    return 0;
}

void find_two_largest(int n, int a[n], int *largest, int *second_largest) {
    *largest = a[0];
    *second_largest = a[1];

    for (int i = 0; i < n; i++) {
        if (a[i] > *largest) {
            *second_largest = *largest;
            *largest = a[i];
        }
        if (a[i] < *largest && a[i] > *second_largest) {
            *second_largest = a[i];
        }
    }
}