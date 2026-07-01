/* Translate word to scrabble points -> count individual characters and sum it*/
/*AEILNORSTU = 1, DG = 2, BCMP = 3, FHVWY = 4, K = 5, JX = 8, QZ = 10*/

#include <stdio.h>
#include <ctype.h>

int calc_points(char ch);

int main(void) {
    char ch;
    int counter = 0;

    printf("Enter a word: ");

    ch = getchar();
    while (ch != '\n') {
        counter += calc_points(ch);
        ch = getchar();
    }
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