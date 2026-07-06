/* enter size of the magic square and print it*/
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>


#define LEN ((int) (sizeof(counter) / sizeof(counter[0])))


int main(void) {
    int n;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99\n");
    printf("Enter size of magic square: ");
    scanf("%d", &n);

    if ((n % 2) == 0) {
        printf("Only odd number allowed\n");
        return 1;
    }

    int arr[n][n];

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }


    // 1 should in in middle of first row
    arr[0][n/2] = 1;
    int pos_1 = 0;
    int pos_2 = n / 2;
    int next_1 = 0;
    int next_2 = 0;
    int num = 2;

    while (num <= (n * n) ) {
        
        if ((pos_1 - 1) < 0) {
            next_1 = n - 1;
        } else {
            next_1 = pos_1 - 1;
        }

        if ((pos_2 + 1) >= n) {
            next_2 = 0;
        } else {
            next_2 = pos_2 + 1;
        }

        if (arr[next_1][next_2] == 0) {
            arr[next_1][next_2] = num;
            pos_1 = next_1;
            pos_2 = next_2;
        } else {
            arr[pos_1 + 1][pos_2] = num;
            pos_1 = pos_1 + 1;
        }

        // update 
        num++;
    }


    // print solved array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}
