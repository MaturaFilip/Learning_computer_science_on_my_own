/*
    - lined list implementation
*/
#include <stdio.h>
#include <stdlib.h>
#include "stackADT2.h"

// indicate which function adn variables are public and private
// limited to a single file
#define PUBLIC  /* empty */
#define PRIVATE static

#define STACK_SIZE 100


PUBLIC struct node {
    // data is now type Item
    void *data;
    struct node *next;
};

//PRIVATE struct node *top = NULL;
// a pointer to the first node in the list
struct stack_type {
    struct node *top;
    int len;
};

PRIVATE void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

PUBLIC Stack create(void) {
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL) {
        terminate("Error in create: stack could not be created.");
    }
    s->top = NULL;
    s->len = 0;
    return s;
}

PUBLIC void destroy(Stack s) {
    // RELEASE MEMORY OCCUPIED BY THE NODES IN THE LINKED LIST
    make_empty(s);
    // release memory for the stack_type structure
    free(s);
}

PUBLIC void make_empty(Stack s) {
    while (!is_empty(s)) {
        pop(s);
    }
}

PUBLIC bool is_empty(Stack s) {
    return s->top == NULL;
}

// no limit size
PUBLIC bool is_full(Stack s) {
    return false;
}

PUBLIC void push(Stack s, void *p) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        terminate("error in push: stack is full.");
    }

    new_node->data = p;
    new_node->next = s->top;
    s->top = new_node;
    s->len++;
}

PUBLIC void *pop(Stack s) {
    struct node *old_top;
    void *i;

    if (is_empty(s)) {
        terminate("Error in pop: stack is empty.");
    }

    old_top = s->top;
    i = old_top->data;
    s->top = old_top->next;
    s->len--;
    free(old_top);
    return i;
}

PUBLIC void *peek(Stack s) {
    if (is_empty(s)) {
        terminate("Error in peek: stack is empty.");
    }

    return s->top->data;
}

PUBLIC int length(Stack s) {
    return s->len;
}