/* simulate game of craps */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void craps(void);
char get_answer(void);
int get_roll_sum(void);

int main(void) {
    srand ((unsigned) time(NULL));
    craps();
    return 0;
}

void craps(void) {
    int wins = 0, losses = 0, point, sum_dice;
    char ch;
    bool second_game = false;
    while(1) {

        sum_dice = get_roll_sum();

        printf("You rolled: %d\n", sum_dice);

        // FIRST ROUND
        if (!second_game) {
            //WIN
            if (sum_dice == 7 || sum_dice == 11) {
                printf("You win!\n");
                wins += 1;

            //LOSS
            } else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12) {
                printf("You lose!\n");
                losses += 1;
            
            //POINT -> other roll
            } else {
                printf("Your points is %d\n", sum_dice);
                second_game = true;
                point = sum_dice;
                continue;
            }
        }

        //SECOND ROUND -> differend rules
        if (second_game) {
            //WIN
            if (sum_dice == point) {
                printf("You win!\n");
                wins += 1;
            //LOSS
            } else if (sum_dice == 7) {
                printf("You lose!\n");
                losses += 1;
            //GAME CONTINUE
            } else {
                continue;
            }
        }

        printf("\nPlay again? (y/N) ");

        ch = get_answer();

        if (toupper(ch) == 'Y') {
            second_game = false;
            continue;
        } else {
            printf("Wins: %d    Losses: %d\n", wins, losses);
            exit(0);
        }
    }
}

char get_answer(void) {
    char ch;
    scanf(" %c", &ch);
    return ch;
}

int get_roll_sum(void) {

    int dice_1 = (rand() % 6) + 1;
    int dice_2 = (rand() % 6) + 1;
    return dice_1 + dice_2;
} 