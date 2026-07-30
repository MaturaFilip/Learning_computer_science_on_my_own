/* Input two words and program check if the words are anagrams. Ignor all non-alphabet characters*/

/*
    Implement:
        bool are_anagrams(const char *word1, const char *word2);
*/
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>


bool are_anagrams(const char *word1, const char *word2);
int read_line(char str[], int n);

#define WORD_LEN 20

int main(void) {
    char word_1[WORD_LEN];
    char word_2[WORD_LEN];

    printf("Enter first word: ");
    read_line(word_1, WORD_LEN);

    printf("Enter second word: ");
    read_line(word_2, WORD_LEN);
    
    bool anagram = are_anagrams(word_1, word_2);

    if (anagram) {
        printf("The words are anagrams");
    } else {
        printf("The words are not anagrams.");
    }

    printf("\n");
    return 0;
}


bool are_anagrams(const char *word1, const char *word2) {
    int counter[26] = { 0 };
    int len_counter = ((int) (sizeof(counter) / sizeof(counter[0])));
    
    while (*word1) {
        if (isalpha(*word1)) {
            counter[tolower(*word1) - 'a'] += 1;
        }
        word1++;
    }
    while (*word2) {
        if (isalpha(*word2)) {
            counter[tolower(*word2) - 'a'] -= 1;
        }
        word2++;
    }

    for (int i = 0; i < len_counter; i++) {
        if (counter[i] != 0) {
            return false;
        }
    }
    return true;
}

int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';  /* terminates string */
    return i;   /* number of characters stored */
}