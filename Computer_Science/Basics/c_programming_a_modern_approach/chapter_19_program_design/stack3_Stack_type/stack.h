/*
    - just header file to show how can be interface iplemented
    - function in stack.c are changed also
*/
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#define STACK_SIZE 100


/*
    * User can now create multiple instances of the object
    * we need to use pointers now (functions modify the stack)
    * is_empty() and is_full() doesn't need to be a pointer
    * Stack != abstract data type (nothing prevents clients 
    *                              from using a Stack variable
    *                               as a structure)
    * Stack s1;
    * s1.top = 0;   // legal... > we want to prevent this! > stackADT

    Stack s1, s2;
    make_empty(&s1)
    push(&s1, 10);

*/
typedef struct {
    int contents[STACK_SIZE];
    int top;
} Stack;


void make_empty(Stack *s);
bool is_empty(const Stack *s);
bool is_full(const Stack *s);
void push(Stack *, int i);
int pop(Stack *s);

#endif
