/* reverse sentence with arrays. Stop characters: !?. */
#include <ctype.h>
#include <stdio.h>


int main(void) {
    char sentence[150];
    char ch;
    int pointer_to_arr = 0;
    char termination_char;
    int spaces = 0;
    int word_len;

    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n') {

        if (ch == '!' || ch == '?' || ch == '.') {
            termination_char = ch;
            break;
        }

        sentence[pointer_to_arr] = ch;
        pointer_to_arr++;
    }

    printf("Reversal of sentence:");

    word_len = 0;
    for (int i = (pointer_to_arr -1); i >= 0;) {



        if (sentence[i] == ' ' || i == 0) {

            // start printing till word is readed
            for (int j = i; j <= (i + word_len); j++) {
                printf("%c", sentence[j]);
            }

            if (i != 0) {
                printf(" ");
            }

            i--;
            word_len = 0;
            continue;
        }
        i--;
        word_len++;
    }

    printf("%c\n", termination_char);

    return 0;
}
