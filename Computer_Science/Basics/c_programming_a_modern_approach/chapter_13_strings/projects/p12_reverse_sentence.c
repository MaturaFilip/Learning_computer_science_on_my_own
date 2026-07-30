/* reverse sentence with arrays. Stop characters: !?. */
/*
    Store words in 2D array (each row = single word)
    No more than 30 words and no word is more than 20 char long
    Be sure to store a null character at the end of each word so
    it can be treated as a string
*/
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define WORDS_COUNT 30
#define WORD_LEN 20

int main(void) {
    char words[WORDS_COUNT][WORD_LEN + 1];
    char termination_char;
    int word_len;
    int i;

    printf("Enter a sentence: ");
    
    for (i = 0; i < WORDS_COUNT; i++) {
        scanf("%s", words[i]);

        // we need to get terminating character
        word_len = strlen(words[i]);

        if (words[i][word_len - 1] == '!' || words[i][word_len - 1] == '?' || words[i][word_len - 1] == '.') {
            termination_char = words[i][word_len - 1];

            // remove termination character from the string
            if (words[i][word_len - 2] != ' ') {
                words[i][word_len - 1] = '\0';
            } 
            break;
        }
    }
    for (int j = 0; i >= j; i--) {
        if (i == j) {
            printf("%s", words[i]);
        } else {
            printf("%s ", words[i]);
        }  
    }
    printf("%c\n", termination_char);
    
    return 0;
}

