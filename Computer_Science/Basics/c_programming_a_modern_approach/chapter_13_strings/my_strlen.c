/* my strlen version */

#include <stdio.h>


size_t my_strlen(const char *s) {
    const char *p = s;

    // go to the end of a array (it points to \0)
    // in the end it points to \n
    while (*s) {
        s++;
    }
    // distance between s and p
    return s - p;
}

// slower strlen

size_t my_strlne_v2(const char *s) {
    size_t n = 0;

    // in the end it points + 1 after \n
    while (*s++) {
        n++;
    }
    return n;
}