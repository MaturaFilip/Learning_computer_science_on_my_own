
#include <stdio.h>

int main(void) {

    printf("%d\n", count_spaces("ahoj jak se mas"));
    return 0;
}


int count_spaces(const char s[]) {
    int count = 0;
    while (*s) {
        if (*s++ == ' ') {
            count++;
        }
    }
    return count;
}