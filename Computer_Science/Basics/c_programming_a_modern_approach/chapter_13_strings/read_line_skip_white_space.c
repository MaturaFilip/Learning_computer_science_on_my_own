/* Have it skip white space before beginning to store input characters */
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

    // skip white space
    while ((ch = getchar()) != '\n') {
        if (i == 0 && ch == ' ') {
            continue;
        }
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';  /* terminates string */
    return i;   /* number of characters stored */
}