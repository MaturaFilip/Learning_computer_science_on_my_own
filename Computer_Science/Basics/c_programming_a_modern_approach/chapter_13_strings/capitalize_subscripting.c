/*
Rewrite "capitalize", this time using pointer arithmetic to access the characters
    in the string.
*/

#include <ctype.h>
#include <stdio.h>

void capitalize(char str[]);

int main(void) {

    char message[] = "abcd";
    capitalize(message);
    printf("%s\n", message);
}


void capitalize(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}
