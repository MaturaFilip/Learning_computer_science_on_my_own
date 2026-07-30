/* Translate word to scrabble points -> count individual characters and sum it*/
/*AEILNORSTU = 1, DG = 2, BCMP = 3, FHVWY = 4, K = 5, JX = 8, QZ = 10*/
/*
    Include following function:
        int compute_scrabble_value(const char *word);
    The function returns the Scrabble vlue of the string pointer to by "word"
*/

#include <stdio.h>
#include <ctype.h>

#define WORD_LEN 30

int calc_points(char ch);
int compute_scrabble_value(const char *word);
int read_line(char str[], int n);

int main(void) {
    char word[WORD_LEN];
    char ch;
    int counter;

    printf("Enter a word: ");
    read_line(word, WORD_LEN);
    counter = compute_scrabble_value(word);
    
    printf("Scrabble value: %d\n", counter);
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

int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';  /* terminates string */
    return i;   /* number of characters stored */
}