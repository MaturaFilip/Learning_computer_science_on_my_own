/* Declaration 8x8 char array checker board */
#include <stdio.h>

#define LEN ((int) (sizeof(checker_board) / sizeof(checker_board[0])))

int main() {

    char checker_board[8][8];
    
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            if ((i + j) % 2 == 0) {
                checker_board[i][j] = 'B';
                printf("%c ", checker_board[i][j]);

            } else {
                checker_board[i][j] = 'R';
                printf("%c ", checker_board[i][j]);
            }
        }
        printf("\n");
    }


    return 0;
}