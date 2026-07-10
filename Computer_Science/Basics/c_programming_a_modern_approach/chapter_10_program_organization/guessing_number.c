/* Asks user to guess a hidden number */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_NUMBER 100

/* global <external> variable */
int secret_number;

/* pprototypes */
void initialize_number_generator(void);
void choose_new_secret_number(void);
void read_guesses(void);

int main(void) {
    char command;

    printf("Guess the secret number between 1 and %d. \n\n", MAX_NUMBER);
    initialize_number_generator();

    do {
        choose_new_secret_number();
        printf("A new number has been chosen.\n");
        read_guesses();
        printf("Play again? (Y/N) ");
        scanf(" %c", &command);
        printf("\n");
    } while (tolower(command) == 'y');

    return 0;
}

// initialize the random number generator
void initialize_number_generator(void) {
    srand((unsigned) time(NULL));
}

// generate number
void choose_new_secret_number(void) {
    secret_number = rand() % MAX_NUMBER + 1;
}

// read user guesses
void read_guesses(void) {
    int guess, number_guesses = 0;

    for ( ;; ) {
        number_guesses += 1;

        printf("Enter guess: ");
        scanf("%d", &guess);

        if (guess == secret_number) {
            printf("You won in %d guesses!\n\n", number_guesses);
            return;
        } else if (guess < secret_number) {
            printf("Too low; try again.\n");
        } else {
            printf("Too high; try again.\n");
        }
    }
}