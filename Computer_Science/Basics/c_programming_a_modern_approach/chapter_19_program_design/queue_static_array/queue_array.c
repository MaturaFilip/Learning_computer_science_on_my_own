#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define PUBLIC  /* empty */
#define PRIVATE static
#define QUEUE_SIZE 100

/*
    - "Item" type defined inside header file
*/

PUBLIC struct queue_type {
    Item contents[QUEUE_SIZE];
    int front_point;
    int rear_point;
    int size;
};

PRIVATE void terminate(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

PUBLIC Queue create(void) {
    // return pointer to the queue_type struct
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL) {
        terminate("Error in create: queue could not be created.");
    }
    q->front_point = 0;
    q-> rear_point = 0;
    q->size = 0;
    return q;
}

// we can destroy just the Queue (not like linked-list, dynamic arrays)
PUBLIC void destroy(Queue q) {
    free(q);
}

PUBLIC void enqueue(Queue q, Item i) {
    // check if queue is full
    if (is_full(q)) {
        terminate("Error in enqueue: queue is full.");
    }

    q->contents[q->rear_point] = i;
    // if the rear point after +1 will pass QUEUE_SIZE
    // modulo operator will wrap around again to 0
    q->rear_point = (q->rear_point + 1) % QUEUE_SIZE;
    q->size++;
}

PUBLIC Item dequeue(Queue q) {
    if (is_empty(q)) {
        terminate("Error in dequeue: queue is empty.");
    }
    Item value = q->contents[q->front_point];
    // front_point is incremented
    q->front_point = (q->front_point + 1) % QUEUE_SIZE;
    q->size--;

    return value;
}

PUBLIC Item peek(Queue q) {
    if (is_empty(q)) {
        terminate("Error in peek. queue is empty.");
    }
    return q->contents[q->front_point];
}

PUBLIC Item rear(Queue q) {
    if (is_empty(q)) {
        terminate("Error in rear. queue is empty.");
    }
    // needed because rear_point is pointing to next empty slot
    int last_index = (q->rear_point - 1 + QUEUE_SIZE) % QUEUE_SIZE;
    return q->contents[last_index];
}

PUBLIC bool is_empty(Queue q) {
    return q != NULL && q->size == 0;
}

PUBLIC void make_empty(Queue q) {
    if (q != NULL) {
        q->front_point = 0;
        q->rear_point = 0;
        q->size = 0;
    }
}

PUBLIC bool is_full(Queue q) {
    return q != NULL && q->size == QUEUE_SIZE;
}
