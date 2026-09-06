#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int coleman_liau_index(const char *text);

int main(void) {

    string text = get_string("Text: ");
    int index = coleman_liau_index(text);

    if (index < 2.0) {
        printf("Before Grade 1\n");
    } else if (index >= 16.0) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", index);
    }

    return 0;
}

int coleman_liau_index(const char *text) {
    // 0.0588 * L - 0.296 * S - 15.8
    // L = average number of letters per 100 words
    // S is average number of sentences per 100 words
    float letters = 0;
    float words = 0;
    float sentences = 0;
    int i;
    int  text_len = strlen(text);


    for (i = 0; i < text_len; i++) {
        // count letters
        if (isalpha(text[i])) {
            letters += 1;
        }

        // count words
        if (text[i] == ' ') {
            words += 1;
        }


        // count sentences
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences += 1;
        }
    }
    // end of string
    words++;
    double index = round(0.0588 * ((letters / words) * 100) - 0.296 * ((sentences / words) * 100) - 15.8);
    return (int) index;
}
