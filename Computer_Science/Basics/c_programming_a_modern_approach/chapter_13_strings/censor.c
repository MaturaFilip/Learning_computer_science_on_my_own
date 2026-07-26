/*
   Write a function "censor" that modifies a string by replacing
   every occurence of "foo" by "xxx". For instance, the string
   "food fool" would become "xxxd xxxl". ake the function as short
   as possible without sacrificing clarity
*/

#include <ctype.h>
#include <stdio.h>

void censor(char str[]);

int main(void) {

    char message[] = "food fool";
    censor(message);
    printf("%s\n", message);
}

// replace "foo" by "xxx"
void censor(char str[]) {
    while (*str) {
        if (*str == 'f' && *(str + 1) == 'o' && *(str + 2) == 'o') {
            *str = *(str + 1) = *(str + 2) = 'x';
        }
        str++;
    }
}