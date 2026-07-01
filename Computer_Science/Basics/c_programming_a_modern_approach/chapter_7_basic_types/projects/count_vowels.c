/* Enter a sentence and output show you how many vowels are in the sentence*/
#include <ctype.h>
#include <stdio.h>

int check_vowel(char ch);

int main(void) {
    char ch;
    int counter = 0;

    printf("Enter a message: ");
    ch = getchar();

    while (ch != '\n') {
        if (check_vowel(ch)) {
            counter += 1;
        }
        ch = getchar();
    }
    printf("Your sentence contains %d vowels\n", counter);

    return 0;
}

int check_vowel(char ch) {
    switch (toupper(ch)) {
        case 'A': case 'E': case 'I': case 'O': case 'U':
            return 1;

        default:
            return 0;
    }
}