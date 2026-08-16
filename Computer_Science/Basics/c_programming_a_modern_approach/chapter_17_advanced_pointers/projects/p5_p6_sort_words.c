/*
    - user enter words (stop when just enter is pressed)
    - sort the words and print it
    - store each word in dynamically allocated string (array of pointers)
    - use read_line from remind2.c
    - p6 -> use qsort() to sort array of pointers to string
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define WORD_LEN 20
#define MAX_WORDS 50    // maximum words entered by user

int read_line(char str[], int n);
int compar(void const* va, void const* vb);

int main(void) {
    char *words[MAX_WORDS];
    char word[WORD_LEN + 1];
    int num_words = 0, i;

    for (;;) {
        if (num_words == MAX_WORDS) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter a word: ");
        read_line(word, WORD_LEN);

        if (strlen(word) == 0) {
            break;
        }

        words[num_words] = malloc(strlen(word) + 1);
        if (words[num_words] == NULL) {
            printf("-- No space left --\n");
            break;
        }

        strcpy(words[num_words], word);
        num_words++;

    }
    qsort(words, num_words, sizeof(words[0]), compar);
    for (i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }
    return 0;
}


int read_line(char str[], int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';

	return i;
}

int compar(void const* va, void const* vb) {
  const char* a = *(char* const*)va;
  const char* b = *(char* const*)vb;
  return strcmp(a, b);
}

