/* Have it stop reading at the first new-line character, then store the new-line character, then store the new-line character in the string */


#include <ctype.h>
#include <stdio.h>
int read_line(char str[], int n);

#define STR_LEN 20
int main(void) {

    char message[STR_LEN - 1];
    read_line(message, STR_LEN);
    // without \n
    printf("%s", message);
}

int read_line(char str[], int n) {
    int ch, i = 0;

    do {
        ch = getchar();

        if (i < n) {
            str[i++] = ch;
        }
    } while (ch != '\n');

    str[i] = '\0'; /* terminates string*/
    return i;   /* number of characters stored */
}