/* have it stop reading at the first white-space character. Hint: to determine whether or not a character is white space, call the "isspace" function */

#include <ctype.h>
#include <stdio.h>
int read_line(char str[], int n);

#define STR_LEN 20
int main(void) {

    char message[STR_LEN - 1];
    read_line(message, STR_LEN);
    printf("%s\n", message);
}

int read_line(char str[], int n) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n') {
        // stop after first white-space
        if (isspace(ch)) {
            break;
        }
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';  /* terminates string */
    return i;   /* number of characters stored */
}