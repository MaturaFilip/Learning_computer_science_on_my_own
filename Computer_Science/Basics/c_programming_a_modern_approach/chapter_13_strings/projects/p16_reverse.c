/* Etner a message and print reverse. Store each character in a array */

/*
    Implement:
        void reverse(char *message);
    The function reverse the string pointed to by message.
    Hint: use 2 pointers: pointing to 1 character and last character
*/

#include <stdio.h>

#define ARR_LEN 100
#define MESSAGE_LEN 100

void reverse(char *message);
int read_line(char str[], int n);

int main(void) {
    char message[MESSAGE_LEN];
    printf("Enter a message: ");
    read_line(message, MESSAGE_LEN);
    reverse(message);
    printf("Reversal is: %s\n", message);

    return 0;
}

void reverse(char *message) {
    char *p = message;
    char *q = message;

    while (*q) {
        q++;
    }
    q--;


    for (; p <= q; p++, q--) {
        char temp = *p;
        *p = *q;
        *q = temp;
    }
}

int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';  /* terminates string */
    return i;   /* number of characters stored */
}