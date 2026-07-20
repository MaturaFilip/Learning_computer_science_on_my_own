/* Rewrite project 14 from chapter 8 and use pointers */
/* reverse sentence with arrays. Stop characters: !?. */
/*
Enter a sentence: I made a mistake
Reversal of sentence: mistake  a  made I
*/

#include <ctype.h>
#include <stdio.h>

#define LEN 150
int main(void) {
    char sentence[LEN];
    char ch;
    char termination_char;
    char *p = sentence;

    // Read a message
    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n' && p < sentence + LEN) {
        if (ch == '!' || ch == '?' || ch == '.') {
            termination_char = ch;
            break;
        }
        *p++ = ch;
    }


    printf("Reversal of sentence:");
    char *q = p;
    char *p_back;
    for (; p >= sentence;) {

        if (*p == ' ') {

            // start printing till word is readed
            p_back = p;
            for (; p <= q; p++) {
                printf("%c", *p);
            }
            printf(" ");
            p = p_back;
        }

        if (p == sentence) {
            for (; p < p_back; p++) {
                printf("%c", *p);
            }
            break;
        }
        p--;
    }
    printf("%c\n", termination_char);
    return 0;
}
