#include <stdio.h>
#include <cs50.h>

int main(void) {
    int owed;

    do {
        owed = get_int("Change owed: ");
    } while (owed <= 0);

    int coin_counter = 0;

    while (owed >= 25) {
        coin_counter += 1;
        owed -= 25;
    }

    while (owed >= 10) {
        coin_counter += 1;
        owed -= 10;
    }

    while (owed >= 5) {
        coin_counter += 1;
        owed -= 5;
    }

    while (owed >= 1) {
        coin_counter += 1;
        owed -= 1;
    }

    printf("%d\n", coin_counter);

}

