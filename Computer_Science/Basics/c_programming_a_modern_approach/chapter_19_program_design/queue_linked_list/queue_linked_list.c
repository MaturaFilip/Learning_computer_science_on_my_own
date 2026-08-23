/*
    - lined list implementation
*/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// indicate which function adn variables are public and private
// limited to a single file
#define PUBLIC  /* empty */
#define PRIVATE static

PUBLIC struct node {
    // data is now type Item
    Item data;
    struct node *next;
};

//PRIVATE struct node *top = NULL;


struct queue_type {
    // a pointer to the first node in the list
    struct node *first;
    // a pointer to the last node in the list
    struct node *last;
};

// a pointer to the last node in the list


PRIVATE void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

PUBLIC Queue create(void) {
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL) {
        terminate("Error in create: queue could not be created");
    }
    q->first = NULL;
    q->last = NULL;
    return q;
}

PUBLIC void destroy(Queue q) {
    // RELEASE MEMORY OCCUPIED BY THE NODES IN THE LINKED LIST
    make_empty(q);
    // release memory for the queue_type strcture
    free(q);
}

// TO REVIEW
PUBLIC void make_empty(Queue q) {
    while (!is_empty(q)) {
        struct node *temp = q->first;
        q->first = q->first->next;
        free(temp);
    }
    q->last = NULL;
}

//[DONE]
PUBLIC bool is_empty(Queue q) {
    return q->first == NULL;
}

// no limit size
// [DONE]
PUBLIC bool is_full(Queue q) {
    return false;
}

PUBLIC Item peek(Queue q) {
    if (is_empty(q)) {
        terminate("Error in peek. queue is empty.");
    }
    return q->first->data;
}

PUBLIC Item rear(Queue q) {
    if (is_empty(q)) {
        terminate("Error in rear. queue is empty.");
    }
    return q->last->data;
}

PUBLIC void enqueue(Queue q, Item i) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        terminate("Error in enqueue.");
    }
    // last node
    new_node->data = i;
    new_node->next = NULL;

    if (is_empty(q)) {
        q->first = new_node;
    } else {
        q->last->next = new_node;
    }

    q->last = new_node;
}


PUBLIC Item dequeue(Queue q) {
    struct node *old_first;
    Item i;

    if (is_empty(q)) {
        terminate("Error in dequeue: queue is empty.");
    }

    old_first = q->first;
    i = old_first->data;

    q->first = old_first->next;
    // handle situation if queue become empty
    if (q->first == NULL) {
        q->last = NULL;
    }

    free(old_first);
    return i;
}

