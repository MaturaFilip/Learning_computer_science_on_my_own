#include <stdio.h>
#include "quicksort.h"

#define N 10

int main(void)
{
    int a[N], i;

    printf("Enter %d numbers to be sorted: ", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    // Define pointers
    int *s = a;
    int *e = a + (N - 1);

    quicksort(a, s, e);

    printf("In sorted order: ");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}