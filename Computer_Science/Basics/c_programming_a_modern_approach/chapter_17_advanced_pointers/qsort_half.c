/* 100 elements in array, sort just 50 last elements */

#include <stdio.h>
#include <stdlib.h>
#define N 10

int compare(const void *a, const void *b) {
    int *valA = a;
    int *valB = b;
    return *valA - *valB;
}

int compare_desc(const void *a, const void *b) {
    int *valA = a;
    int *valB = b;
    return *valB - *valA;
}

int main(void) {
    int arr[N] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    int *p = &arr[N / 2];
    qsort(p, (N / 2), sizeof(arr[0]), compare);

    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int arr_2[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    qsort(arr_2, N, sizeof(arr_2[0]), compare_desc);

    for (int i = 0; i < N; i++) {
        printf("%d ", arr_2[i]);
    }
    printf("\n");
    return 0;
}