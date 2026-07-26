/*
Write a function "capitalize" that capitalizes all letters in its argument,
    the argument will be a null-terminated string containing arbitary chracters,
    not just letters. Use array subscripting to access the characters in the string. 
    Hint: Use the "toupper" function to convert each character to upper-case
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
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}
