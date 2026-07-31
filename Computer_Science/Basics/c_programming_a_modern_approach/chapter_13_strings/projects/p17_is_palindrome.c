/* Etner a message and check if it's a palindrome */

/*
    Implement:
        bool is_palindrome(const char *message);
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MESSAGE_LEN 100

//void is_palindrome(char *a, char *last);
bool is_palindrome(const char *message);
int read_line(char str[], int n);

int main(void) {
    bool is_pal;
    char message[MESSAGE_LEN];
    printf("Enter a message: ");
    read_line(message, MESSAGE_LEN);

    is_pal = is_palindrome(message);

    if (is_pal) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }
}


bool is_palindrome(const char *message) {
    const char *p = message;
    const char *q = message;

    while (*q) {
        q++;
    }
    q--;

    for (; p <= q; p++, q--) {
        if (*p != *q) {
            return false;
        }
    }
    return true;
}

int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && isalpha(ch))
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';  /* terminates string */
    return i;   /* number of characters stored */
}