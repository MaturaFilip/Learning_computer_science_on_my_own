/* Sorts an array of integer using Quicksort */
/* low, high, middle are pointers to array elements rather than integers */
/* The "split" function will need to return a pointer, not integer*/

#include <stdio.h>

#define N 10

void quicksort(int a[], int *low, int *high);
int *split(int a[], int *low, int *high);

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

// quicksort call
void quicksort(int a[], int *low, int *high)
{
    int *middle;

    if (low >= high) return;
    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

// set pivot and rearange the array in way that pivot is 
// in the middle of the array/sub-array, lower values to
// the left of the array and higher value in the right side
int *split(int a[], int *low, int *high)
{
    int part_element = *low;

    for (;;)
    {
        while (low < high && part_element <= *high) {
            high--;
        }
        if (low >= high) {
            break;
        }
        *low++ = *high;


        while (low < high && *low <= part_element) {
            low++;
        }
        if (low >= high) {
            break;
        }
        *high-- = *low;
    }

    *high = part_element;
    return high;
}