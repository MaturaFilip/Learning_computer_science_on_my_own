/* loop over 2D array with one loop */

#include <stdio.h>

#define NUM_ROWS 10
#define NUM_COLS 10

int main(void) {
    int a[NUM_ROWS][NUM_COLS];
    int *p;

    for (p = &a[0][0]; p <= &a[NUM_ROWS - 1][NUM_COLS - 1]; p++) {
        *p = 0;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}