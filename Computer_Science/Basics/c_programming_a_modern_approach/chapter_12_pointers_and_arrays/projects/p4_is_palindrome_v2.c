/* Siplify programming project 2(b) by taking advantage of the fact that an array name can be used as a pointer */

/* Etner a message and check if it's a palindrome */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define ARR_LEN 100

void is_palindrome(char *a, char *last);

int main(void) {
    char message[ARR_LEN];
    char ch;
    char *p = message;

    printf("Enter a message: ");
    while ((ch = getchar()) != '\n' && p < message + ARR_LEN) {
        if (isalpha(ch)) {
            *p++ = ch;
        }
    }

    is_palindrome(message, p);
}

void is_palindrome(char *a, char *last) {
    char *q = a;
    for (; q <= --last; q++) {
        if (tolower(*q) == tolower(*last)) {
            continue;
        } else {
            printf("Not a palindrome\n");
            exit(1);
        }
    }
    printf("Palindrome\n");
}