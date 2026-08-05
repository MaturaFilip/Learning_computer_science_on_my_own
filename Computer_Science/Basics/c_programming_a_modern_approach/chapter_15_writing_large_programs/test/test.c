#include <stdio.h>
#include "word.h"

#define MAX_WORD_LEN 20

int main(void) {
    char word[MAX_WORD_LEN + 2];
    int word_len;

    word_len = read_word(word, MAX_WORD_LEN + 1);
    printf("%s\n", word);
    printf("%d\n", EOF);
}