#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// indicate which function adn variables are public and private
// limited to a single file
#define PUBLIC  /* empty */
#define PRIVATE static

#define STACK_SIZE 100


PUBLIC struct node {
    int data;
    struct node *next;
};

PRIVATE struct node *top = NULL;

PRIVATE void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

PUBLIC void make_empty(void) {
    while (!is_empty()) {
        pop();
    }
}

PUBLIC bool is_empty(void) {
    return top == NULL;
}

// no limit size
PUBLIC bool is_full(void) {
    return false;
}

PUBLIC void push(int i) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        terminate("error in push: stack is full.");
    }

    new_node->data = i;
    new_node->next = top;
    top = new_node;
}

PUBLIC int pop(void) {
    struct node *old_top;
    int i;

    if (is_empty()) {
        terminate("Error in pop: stack is empty.");
    }

    old_top = top;
    i = top->data;
    top = top->next;
    free(old_top);
    return i;
}