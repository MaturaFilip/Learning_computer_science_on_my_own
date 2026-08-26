/*
    - implementation of stack with incomplete type e.g. "struct t;"
    - type remains incomplete -> its uses are limited

    struct t s;     // ilegal

    - it is legal to define a pointer type that references and incomplete type:

    typedef struct t *T;        // but can't apply "->" (compiler know nothing about members of a t struct)

    ///////
    - pointer to type can be used like this:
        typedef float *Temperature;
        float s1 = 12.5;

        // no need to use float *s2!
        Temperature s2 = &s1;
        printf("%f\n", *s2);


    - Items in stack ust be integers -> implement a change, so we can use every type we want
*/
#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h> 

/*
    - represent the type of data to be stored in QUEUE
*/
typedef int Item;

// Queue type is a pointer to queue_type that stores the actual contents of the stack
// queue_type structure is INCOMPLETE -> will be copleted in the file that implement stack
typedef struct queue_type *Queue;

// type Queue = pointer to incomplete queue_type
// ADT needs create and destroy functions
Queue create(void);
void destroy(Queue q);

void enqueue(Queue q, Item i);
Item dequeue(Queue q);

// inspect front element of the queue (HEAD)
Item peek(Queue q);

// inspect back element of the queue (TAIL)
Item rear(Queue q);

bool is_empty(Queue q);
bool is_full(Queue q);

// no need for this function
void make_empty(Queue q);

#endif