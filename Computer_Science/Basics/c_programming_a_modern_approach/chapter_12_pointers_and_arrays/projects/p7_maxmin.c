/* Finds the largest and smallest elements in an array */
/* Modify exercise from chapter 11 to use pointers to array, instead of integers */

#include <stdio.h>

 #define ARR_LEN 10

void max_min(int n, int a[n], int *max, int *min);

int main(void) {
    int b[ARR_LEN];
    int big, small;

    printf("Enter %d numbers: ", ARR_LEN);

    // Load array
    for (int i = 0; i < ARR_LEN; i++) {
        scanf(" %d", &b[i]);
    }

    // find largest and smallest element
    max_min(ARR_LEN, b, &big, &small);

    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);

    return 0;
}

void max_min(int n, int a[n], int *max, int *min) {
    *max = *min = *a;

    for (int i = 1; i < ARR_LEN; i++) {

        if (*(a + i) > *max) {
            *max = *(a + i);
        } else if (*(a + i) < *min) {
            *min = *(a + i);
        }
    }
}

