#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define PUBLIC  /* empty */
#define PRIVATE static

/*
    - "Item" type defined inside header file
*/

PUBLIC struct queue_type {
    Item *contents;
    int front_point;
    int rear_point;
    int size;
    int queue_size;
};

PRIVATE void terminate(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

PUBLIC Queue create(int size) {
    // return pointer to the queue_type struct
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL) {
        terminate("Error in create: queue could not be created.");
    }
    q->contents = malloc(size * sizeof(Item));
    if (q->contents == NULL) {
        free(q);
        terminate("Error in create: queue could not be created.");
    }
    q->front_point = 0;
    q-> rear_point = 0;
    q->size = 0;
    q->queue_size = size;
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
    q->rear_point = (q->rear_point + 1) % q->queue_size;
    q->size++;
}

PUBLIC Item dequeue(Queue q) {
    if (is_empty(q)) {
        terminate("Error in dequeue: queue is empty.");
    }
    Item value = q->contents[q->front_point];
    // front_point is incremented
    q->front_point = (q->front_point + 1) % q->queue_size;
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
    int last_index = (q->rear_point - 1 + q->queue_size) % q->queue_size;
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
    return q != NULL && q->size == q->queue_size;
}
