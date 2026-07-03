#include <stdio.h>

#define LEN ((int) (sizeof(number) / sizeof(number[0])))

int main() {

    int number[2][3] = {{1, 2, 3}, {4, 5, 6}};

    /*
    for (int i = 0; i < LEN; i++) {
        printf("%d\n", number[i][i]);
    }*/

    printf("%d\n", number[0][0]);
    printf("%d\n", number[1][0]);
    //printf("%d\n", number[0][0]);
    //printf("%d\n", number[0][0]);
    printf("%d\n", ((int) (sizeof(number) / sizeof(number[0]))));

    return 0;
}