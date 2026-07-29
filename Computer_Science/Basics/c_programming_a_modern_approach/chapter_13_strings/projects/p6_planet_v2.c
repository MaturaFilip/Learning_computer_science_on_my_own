/*
    Update planec.c from section 13.7 to ignore
    case when comparing planets array with
    command-line arguments
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM_PLANETS 9
bool compare_words(char *word_1, char *word_2);

int main(int argc, char *argv[]) {
    char *planets[] = {"Mercury", "Venus", "Earth",
                        "Mars", "Jupiter", "Saturn",
                        "Uranus", "Neptun", "Pluto"};

    int i, j;

    for (i = 1; i < argc; i++) {
        for (j = 0; j < NUM_PLANETS; j++) {
/*
            char *p = argv[i];
            char **q = &planets[j];
            printf("%s\n", *q);
            for ( ; *p; ++p) *p = tolower(*p);
            //for ( ; **q; ++*q) **q = tolower(**q);
*/
            
        if (compare_words(argv[i], planets[j])) {
            printf("%s is planet %d\n", argv[i], j + 1);
            break;
        }
            //if (strcmp(argv[i], planets[j]) == 0) {
            //    printf("%s is planet %d\n", argv[i], j + 1);
            //    break;
            //}
        }
        if (j == NUM_PLANETS) {
            printf("%s is not a planet\n", argv[i]);
        }
    }
    return 0;
}

bool compare_words(char *word_1, char *word_2) {

    if (strlen(word_1) != strlen(word_2)) {
        return false;
    }

    int word_len = strlen(word_1), i;

    for (i = 0; i < word_len; i++) {
        if (tolower(word_1[i]) != tolower(word_2[i])) {
            return false;
        }
    }
    return true;

}