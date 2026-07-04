/* 10x10 random walk */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define LEN ((int) (sizeof(arr) / sizeof(arr[0])))
#define LAST_CHAR 90
#define NUM_DIR 4


int main(void) {
    char arr[10][10];


    // array initialization
    for (int i = 0; i < LEN; i++ ) {
        for (int j = 0; j < LEN; j++) {
            arr[i][j] = '.';
        }
    }  

    int rand_dir;
    //int available_directions;

    srand ((unsigned) time(NULL));

    // starting point -> 0 0
    int position_1 = 0;
    int position_2 = 0;
    arr[position_1][position_2] = 'A';

    for (int i = 66; i < LAST_CHAR; i++) {

        // check available direction
        bool direct[4] = {false};
        for (int available_directions = 4; available_directions > 0; available_directions--) {

            while (1) {
                rand_dir = rand() % NUM_DIR;

                if (direct[rand_dir]) {
                    continue;
                }

                if (available_directions == 1) {
                    break;
                }
                direct[rand_dir] = true;
                break;
            }
            
            // 0 = down, 1 = up, 2 = left, 3 = right
            if (rand_dir == 0 && (position_1 + 1) < 10 && arr[position_1 + 1][position_2] == '.') {
                arr[position_1 + 1][position_2] = (char) i;
                position_1 += 1;
                break;
            } else if (rand_dir == 1 && (position_1 - 1) >= 0 && arr[position_1 - 1][position_2] == '.') {
                arr[position_1 - 1][position_2] = (char) i;
                position_1 -= 1;
                break;
            } else if (rand_dir == 2 && (position_2 - 1) >= 0 && arr[position_1][position_2 - 1] == '.') {
                arr[position_1][position_2 - 1] = (char) i;
                position_2 -= 1;
                break;
            } else if (rand_dir == 3 && (position_2 + 1) < 10 && arr[position_1][position_2 + 1] == '.') {
                arr[position_1][position_2 + 1] = (char) i;
                position_2 += 1;
                break;
            }

            // terminate if no direction and print the array
            if (available_directions == 1) {
                for (int i = 0; i < LEN; i++ ) {
                    for (int j = 0; j < LEN; j++) {
                        printf("%c ", arr[i][j]);
                    }
                    printf("\n");
                    
                }
                printf("Terminated prematurely\n");
                return 1;
            }
        }
    }

    for (int i = 0; i < LEN; i++ ) {
        for (int j = 0; j < LEN; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");            
    }
    return 0;
}