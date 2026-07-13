/* Finds the largest and smallest elements in an array */

#include <stdio.h>

 #define ARR_LEN 10

void max_min(int n, int a[n], int *max, int *min);

int main(void) {
    int b[ARR_LEN], big, small;

    printf("Enter %d numbers: ", ARR_LEN);

    for (int i = 0; i < ARR_LEN; i++) {
        scanf(" %d", &b[i]);
    }

    max_min(ARR_LEN, b, &big, &small);

    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);

    return 0;
}

void max_min(int n, int a[n], int *max, int *min) {
    // initialization
    *max = a[0];
    *min = a[0];

    for (int i = 1; i < ARR_LEN; i++) {
        if (*max < a[i]) {
            *max = a[i];
        } else if (*min > a[i]) {
            *min = a[i];
        }
    }
}

