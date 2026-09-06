#include <stdio.h>
#include <ctype.h>
#include <cs50.h>

int calc_points(char ch);
int compute_scrabble_value(const char *word);

int main(void) {
    string p1 =  get_string("Player 1: ");
    string p2 =  get_string("Player 2: ");

    int p1_count = compute_scrabble_value(p1);
    int p2_count = compute_scrabble_value(p2);

    if (p1_count == p2_count) {
        printf("Tie!\n");
    } else if (p1_count > p2_count) {
        printf("Player 1 wins!\n");
    } else if (p1_count < p2_count) {
        printf("Player 2 wins!\n");
    }
    return 0;
}

int calc_points(char ch) {
    switch(toupper(ch)) {
        case 'A':
        case 'E':
        case 'I':
        case 'L':
        case 'N':
        case 'O':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
            return 1;

        case 'D':
        case 'G':
            return 2;

        case 'B':
        case 'C':
        case 'M':
        case 'P':
            return 3;

        case 'F':
        case 'H':
        case 'V':
        case 'W':
        case 'Y':
            return 4;

        case 'K':
            return 5;

        case 'J':
        case 'X':
            return 8;

        case 'Q':
        case 'Z':
            return 10;

        default:
            return 0;
    }
}

int compute_scrabble_value(const char *word) {
    int counter = 0;
    while (*word) {
        counter += calc_points(*word);
        word++;
    }
    return counter;
}