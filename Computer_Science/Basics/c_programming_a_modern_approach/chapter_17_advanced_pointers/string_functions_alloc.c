#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

char *concat(const char *s1, const char *s2);

int main(void) {
    char *s1 = "abc";
    char *s2 = "def";
    char *c = concat(s1, s2);

    if (c == NULL) {        // USED
        printf("free\n");
    } else {
        printf("used\n");
    }

    printf("%s\n", c);
    free(c);

    printf("%s\n", c);      //GARBAGE

    if (c == NULL) {        // USED
        printf("free\n");
    } else {
        printf("used\n");
    }

    c = NULL; // Good practice to avoid dangling pointers

    if (c == NULL) {        //FREE
        printf("free\n");
    } else {
        printf("used\n");
    }
    return 0;
}

char *concat(const char *s1, const char *s2) {
    char *result;

    result = malloc(strlen(s1) + strlen(s2));
    if (result == NULL) {
        printf("Error: malloc failed in concat\n");
        exit(EXIT_FAILURE);
    }

    strcpy(result, s1);
    strcat(result, s2);
    return result;
}