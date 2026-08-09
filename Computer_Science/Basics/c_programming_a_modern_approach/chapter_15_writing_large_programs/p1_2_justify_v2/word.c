#include <stdio.h>
#include "word.h"

int read_char(void) {
    int ch = getchar();

    return (ch == '\n' || ch == '\t') ? ' ' : ch;
}

int read_word(char *word, int len) {
    int ch, pos = 0;

    // skip all the spaces adn tabs
    while ((ch = read_char()) == ' ') {
        ;
    }

    // read characters until it reaches spaces or EOF
    while (ch != ' ' && ch != EOF) {
        if (pos < len - 1) {
            word[pos++] = ch;
        }
        if (pos == len - 1) {
            word[pos++] = '*';
        }

        ch = read_char();
    }
    word[pos] = '\0';
    return pos;
}