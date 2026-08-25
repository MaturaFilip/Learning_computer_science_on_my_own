#include <stdio.h>
#include <stdlib.h>
#include "stackADT2.h"

#define PUBLIC  /* empty */
#define PRIVATE static

// No need for dynamic arrays
//#define STACK_SIZE 100

/*
    - "Item" type defined inside header file
*/

PUBLIC struct stack_type {
    // we need to change static array to a pointer to the array
    //Item contents[STACK_SIZE];
    // *constents needad for allocation, not contents[]...
    Item *contents;
    int top;
    // size is needed to track array and when to increase it
    // to check for the "stack full" condition
    int size;
};

PRIVATE void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

PUBLIC Stack create(int size) {
    // allocate stack_type
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL) {
        terminate("Error in create: stack could not be created.");
    }

    // allocate the array that will contain the stack items
    s->contents = malloc(size * sizeof(Item));
    if (s->contents == NULL) {
        free(s);
        terminate("Error in create: stack could not be created.");
    }
    s->top = 0;
    s->size = size;
    return s;
}

PUBLIC void destroy(Stack s) {
    // release array and stack_type
    free(s->contents);
    free(s);
}

PUBLIC void make_empty(Stack s) {
    s->top = 0;
}

PUBLIC bool is_empty(Stack s) {
    return s->top == 0;
}

PUBLIC bool is_full(Stack s) {
    return s->top == s->size;
}

PUBLIC void push(Stack s, Item i) {
    if (is_full(s)) {
        // TODO: allocate double size
        terminate("Error in push: stack is full.");
    }
    s->contents[s->top++] = i;
}

PUBLIC Item pop(Stack s) {
    if (is_empty(s)) {
        terminate("Error in pop: stack is empty.");
    }
    return s->contents[--s->top];
}

PUBLIC Item peek(Stack s) {
    if (is_empty(s)) {
        terminate("Error in peek: stack is empty.");
    }
    return s->contents[(s->top)-1];
}

