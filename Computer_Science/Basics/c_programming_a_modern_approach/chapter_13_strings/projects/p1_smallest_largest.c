/* Find first and last word by alphabet */
/* 
    Keep track of smallest and largest during input
    each time user inputs something, use "strcmp"
    use "strcpy" to save the word. Use "strlen" to
    determine when the user has entered a 4-letter
    word
*/


#include <stdio.h>
#include <string.h>


#define WORD_LEN 20
#define EXIT_WORD_LEN 4


int read_line(char str[], int n);

int main(void) {

    // load smallest and largest
    char smallest[WORD_LEN + 1];
    char largest[WORD_LEN + 1];
    for (int i = 0; i < WORD_LEN; i++) {
        smallest[i] = 'z';
        largest[i] = 'a';
    }
    smallest[WORD_LEN] = 0;
    largest[WORD_LEN] = 0;

    // reading user words
    char user_word[WORD_LEN + 1];
    while (1) {
        printf("Enter word: ");
        read_line(user_word, WORD_LEN + 1);

        // check "largest" and "smallest"
        if (strcmp(user_word, smallest) < 0) {
            strcpy(smallest, user_word);
        }

        if (strcmp(user_word, largest) > 0) {
            strcpy(largest, user_word);
        }

        // exit the program and show the "largest" and "smallest"
        if (strlen(user_word) == EXIT_WORD_LEN) {
            break;
        }
    }

    printf("Smallest word: %s\n", smallest);
    printf("Largest word: %s\n", largest);

    return 0;
}

int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';  /* terminates string */
    return i;   /* number of characters stored */
}

