/* Translate message to B1FF filter */
#include <ctype.h>
#include <stdio.h>

char h1ff_filter(char ch);

int main(void) {
    char ch;
    int idx = 0;
    char message[200];

    printf("Enter a message: ");

    while ((ch = getchar()) != '\n') {
        message[idx] = h1ff_filter(toupper(ch));
        idx++;
    }

    for (int i = 0; i < (idx + 1); i++) {
        printf("%c", message[i]);
    }
    printf("!!!!!!!!!!\n");

    return 0;
}

char h1ff_filter(char ch) {
    switch (ch) {
        case 'A':
            return '4';
        case 'B':
            return '8';
        case 'E':
            return '3';
        case 'I':
            return '1';
        case 'O':
            return '0';
        case 'S':
            return '5';
        default:
            return ch;
    }
}
