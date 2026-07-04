/* 5x5 array. User input 5 quiz grades -> calculate total score, avg score for each student, avg, max, min for each quiz */

#include <stdio.h>

#define LEN ((int) (sizeof(matrix) / sizeof(matrix[0])))

int main(void) {
    int matrix[5][5] = { 0 };
    int row_total;
    int column_total;
    int min, max;

    // user input
    for (int i = 0; i < LEN; i++) {
        printf("Enter quiz grades for studnet %d: ", (i + 1));
        
        for (int j = 0; j < LEN; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\n");


    for (int i = 0; i < LEN; i++) {
        printf("Total score and average score for student number %d ", (i + 1));
        row_total = 0;
        for (int j = 0; j < LEN; j++) {
            row_total += matrix[i][j];
        }
        printf("\nTotal score: %d, Avg score: %.2f\n", row_total, (float) row_total / LEN);
    }


    for (int i = 0; i < LEN; i++) {
        printf("Avg, min and max score for quiz %d: ", (i + 1));
        column_total = 0;
        min = 1000;
        max = 0;

        for (int j = 0; j < LEN; j++) {
            column_total += matrix[j][i];
            
            if (matrix[j][i] > max) {
                max = matrix[j][i];
            }

            if (matrix[j][i] < min) {
                min = matrix[j][i];
            }

        }
        printf("\nAvg: %.2f, min: %d, max: %d\n", (float) column_total / LEN, min, max );
    }
    printf("\n");
    return 0;
}
