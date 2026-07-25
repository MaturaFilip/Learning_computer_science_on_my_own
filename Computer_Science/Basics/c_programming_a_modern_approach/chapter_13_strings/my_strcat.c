/* my strcat version - concat two strings*/

#include <stdio.h>

char *my_strcat(char *s1, const char *s2) {
    char *p = s1;

    // go to last element (\0) in the s1 array
    while (*p) {
        p++;
    }

    // start with s2 and co it to \0 of the s1 element
    // null char \0 added from the last element of the s2
    while (*p++ = *s2++) {
        ;
    }

    return s1;
}
