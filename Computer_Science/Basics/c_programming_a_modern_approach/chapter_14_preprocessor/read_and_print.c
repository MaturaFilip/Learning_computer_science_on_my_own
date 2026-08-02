#include <stdio.h>

#define ECHO(s) \
        do {    \
            gets(s); \
            puts(s); \
        }   while (0)

int main(void) {
    char *str;
    ECHO(str);
    return 0;
}