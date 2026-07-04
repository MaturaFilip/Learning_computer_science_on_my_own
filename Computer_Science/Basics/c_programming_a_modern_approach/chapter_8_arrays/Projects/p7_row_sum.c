/* 5x5 array. User input 5 numbers per row and then print row totals and column totals */

#include <stdio.h>

#define LEN ((int) (sizeof(matrix) / sizeof(matrix[0])))

int main(void) {
    int matrix[5][5] = { 0 };
    int row_total;
    int column_total;

    // user input
    for (int i = 0; i < LEN; i++) {
        printf("Enter row %d: ", (i + 1));
        
        for (int j = 0; j < LEN; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\n");
    printf("Row totals: ");

    for (int i = 0; i < LEN; i++) {
        row_total = 0;
        for (int j = 0; j < LEN; j++) {
            row_total += matrix[i][j];
        }
        printf("%d ", row_total);
    }

    printf("\nColumn totals: ");
    for (int i = 0; i < LEN; i++) {
        column_total = 0;
        for (int j = 0; j < LEN; j++) {
            column_total += matrix[j][i];
        }
        printf("%d ", column_total);
    }
    printf("\n");
    return 0;
}
