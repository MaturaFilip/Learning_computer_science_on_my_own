/*Enter a sentence and calculate average word length for a sentence*/
/*
    Implement function below:
        double compute_average_word_length(const char *sentence);
    calculate avg word len from string

    For simplicity the function not handle leading white-space, multiple white-spaces
    between words or trailing white-space
*/
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SENTENCE_LEN 150
double compute_average_word_length(const char *sentence);
int read_line(char str[], int n);

int main(void) {
    char sentence[SENTENCE_LEN];
    printf("Enter a sentence: ");
    read_line(sentence, SENTENCE_LEN);
    double avg_len;
    avg_len = compute_average_word_length(sentence);


    printf("Average word length: %.1f\n", avg_len);

    return 0;
}

double compute_average_word_length(const char *sentence) {
    int total_words = 1;
    int total_length = 0;

    while (*sentence) {
        if (*sentence == ' ') {
            total_words += 1;
        } else {
            total_length += 1;
        }
        sentence++;
    }
    return ((double) total_length / total_words);
}

int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';  /* terminates string */
    return i;   /* number of characters stored */
}