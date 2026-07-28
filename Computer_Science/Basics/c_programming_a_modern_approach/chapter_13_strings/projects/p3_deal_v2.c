/* Deals a random hand of cards */
/* prints the full names of the cards it deals */
/* Your hand:
    Seven of clubs
    Two of spades
    etc.
*/

/* Hint: Replace "rank_code", "suit_code" by arrays containing pointers to strings */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void) {

    // type difinition
    bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
    int num_cards, rank, suit;
    const char *rank_code[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    const char *suit_code[] = {"clubs", "diamons", "hearts", "spades"};

    srand ((unsigned) time(NULL));

    // program
    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);

    printf("Your hand:\n");
    while (num_cards > 0) {
        suit = rand() % NUM_SUITS; /* Picks a random suit */
        rank = rand() % NUM_RANKS;

        if (!in_hand[suit][rank]) {
            in_hand[suit][rank] = true;
            num_cards--;
            printf(" %10s of %s\n", rank_code[rank], suit_code[suit]);
        }
    }
    return 0;
}