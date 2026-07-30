/* Enter a sentence and output show you how many vowels are in the sentence*/
/*
    include function below:
        int compute_vowel_count(const char *sentence);
*/

#include <ctype.h>
#include <stdio.h>

#define SENTENCE_LEN 150

int check_vowel(char ch);
int compute_vowel_count(const char *sentence);
int read_line(char str[], int n);

int main(void) {
    char sentence[SENTENCE_LEN];

    printf("Enter a message: ");
    read_line(sentence, SENTENCE_LEN);
    printf("Your sentence contains %d vowels\n", compute_vowel_count(sentence));

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

int compute_vowel_count(const char *sentence) {
    int counter = 0;
    while (*sentence) {
        counter += check_vowel(*sentence);
        sentence++;
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