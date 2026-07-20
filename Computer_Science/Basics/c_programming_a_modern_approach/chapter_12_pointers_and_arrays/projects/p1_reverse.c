/* Etner a message and print reverse. Store each character in a array*/

#include <stdio.h>

#define ARR_LEN 100
int main(void) {
    char message[ARR_LEN];
    char ch;
    char *p = &message[0];

    printf("Enter a message: ");
    while ((ch = getchar()) != '\n') {
        *p = ch;
        p++;
    }

    printf("Reversal is: ");
    for (p--; p >= &message[0]; p--) {
        printf("%c", *p);
    }
    printf("\n");
    return 0;
}