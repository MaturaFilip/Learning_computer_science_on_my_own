#include <stdio.h>

int main(void) {
    char s[] = "Hsjodi", *p;

    for (p = s; *p; p++) {
        --*p;
    }
    puts(s);
    // this is the princle how this program works
    //printf("%c\n", 'H' - 1);
    return 0;
}