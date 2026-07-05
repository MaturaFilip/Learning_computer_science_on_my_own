/* Translate word to scrabble points -> count individual characters and sum it*/
/*AEILNORSTU = 1, DG = 2, BCMP = 3, FHVWY = 4, K = 5, JX = 8, QZ = 10*/

#include <stdio.h>
#include <ctype.h>

int calc_points(char ch);

//a b c d e f g h i j k l m n o p q r s t u v w x y z
int main(void) {
    char ch;
    int points[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int counter = 0;

    printf("Enter a word: ");
    while ((ch = getchar()) != '\n') {
        counter += points[toupper(ch) - 'A'];
    }
    printf("Scrabble value: %d\n", counter);
    return 0;
}
