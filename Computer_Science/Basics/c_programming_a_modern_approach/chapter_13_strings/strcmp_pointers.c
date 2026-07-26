/* rewrite strcmp from QnA but with pointer arithmetic */
#include <stdio.h>


int my_strcmp(char *s, char *t);

int main(void) {
    char x[] = "abcde";
    char y[] = "abcd";

    printf("%d\n", my_strcmp(x, y));
    return 0;
}

int my_strcmp(char *s, char *t) {

    for (; *s == *t; s++, t++) {
        if (*s == '\0') {
            return 0;
        }
    }
    return *s - *t;
}