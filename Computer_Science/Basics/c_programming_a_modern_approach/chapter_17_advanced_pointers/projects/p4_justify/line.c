#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct node {

    struct node *next;
    char word[];
};

struct node *line = NULL;       // first word
//char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

void clear_line(void) {
    struct node *temp;
    while (line != NULL) {
        temp = line;
        line = line->next;
        free(temp);
    }

    line_len = 0;
    num_words = 0;
}

void add_word(const char *word) {

    struct node *last, *new;

    new = malloc(sizeof(struct node) + strlen(word) + 1);
    if (new == NULL) {
        printf("Memory is full\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new->word, word);
    new->next = NULL;

    if (num_words > 0) {
        line_len++;

        for (last = line; last->next != NULL; last = last->next);
        last->next = new;
    } else {
        line = new;
    }

    line_len += strlen(word);
    num_words++;
}

int space_remaining(void) {
    return MAX_LINE_LEN - line_len;
}

void write_line(void) {
    int extra_spaces, spaces_to_insert, i, j;
    struct node *cur;

    extra_spaces = MAX_LINE_LEN - line_len;

    for (cur = line; cur != NULL; cur = cur->next) {
        printf("%s", cur->word);

        if (num_words > 1) {
            spaces_to_insert = extra_spaces / (num_words - 1);

            for (j = 1; j <= spaces_to_insert + 1; j++) {
                putchar(' ');
            }
            extra_spaces -= spaces_to_insert;
        }
        num_words--;
    }
    putchar('\n');
}

void flush_line(void) {
    struct node *cur;

    if (line_len > 0) {
        printf("%s", line->word);

        for (cur = line->next; cur != NULL; cur = cur->next) {
            printf(" %s", cur->word);
        }
    }
    putchar('\n');
}