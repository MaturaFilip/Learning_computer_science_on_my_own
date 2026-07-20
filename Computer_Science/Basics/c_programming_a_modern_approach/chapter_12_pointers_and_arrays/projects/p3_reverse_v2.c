/* Siplify programming project 1(b) by taking advantage of the fact that an array name can be used as a pointer */

/* Etner a message and print reverse. Store each character in a array*/

#include <stdio.h>

#define ARR_LEN 100
int main(void) {
    char message[ARR_LEN];
    char ch;
    char *p = message;

    printf("Enter a message: ");
    while ((ch = getchar()) != '\n' && p < message + ARR_LEN) {
        *p++ = ch;
    }

    printf("Reversal is: ");
    for (p--; p >= message; p--) {
        printf("%c", *p);
    }
    printf("\n");
    return 0;
}