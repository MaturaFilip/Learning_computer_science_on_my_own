/* Input two words and program check if the words are anagrams. Ignor all non-alphabet characters*/
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>


#define LEN ((int) (sizeof(counter) / sizeof(counter[0])))

bool is_anagram(void);

int main(void) {
    is_anagram();
    return 0;
}

bool is_anagram(void) {
    /*
    Simples version than in book. No need two arrays
    */
    char ch;
    int counter[26] = { 0 };
    bool anagram = true;

    printf("Enter first word: ");
    while ((ch = getchar()) != '\n') {
        
        if (isalpha(ch)) {
            counter[tolower(ch) - 'a'] += 1;
        }
    }

    printf("Enter second word: ");
    while ((ch = getchar()) != '\n') {
        
        if (isalpha(ch)) {
            counter[tolower(ch) - 'a'] -= 1;
        }
    }

    for (int i = 0; i < LEN; i++) {
        if (counter[i] < 0) {
            anagram = false;
        }
    }

    if (anagram) {
        printf("The words are anagrams");
    } else {
        printf("The words are not anagrams.");
    }

    printf("\n");
}