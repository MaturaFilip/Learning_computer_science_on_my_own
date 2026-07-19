/* processing the rows of a multidimensional array */

#include <stdio.h>

#define NUM_ROWS 10
#define NUM_COLS 10

int main(void) {
    int a[NUM_ROWS][NUM_COLS];
    int *p, i = 0;

    for (p = a[i]; p < a[i] + NUM_COLS; p++) {
        *p = 0;
    }

    for (int i = 0; i < 10; i++) {
            printf("%d \n", a[i][0]);
    }


}