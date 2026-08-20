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
#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h> 

/*
    - represent the type of data to be stored on the stack
    - instead of int, you can choose float, double, long etc.
*/
typedef int Item;

// Stack type is a pointer to stack_type that stores the actual contents of the stack
// stack_type structure is incomplete -> will be ocmpleted in the file that implement stack
typedef struct stack_type *Stack;

// type Stack = pointer to incomplete stack_type
// ADT needs create and destroy functions
// create(int size); -> specifies the desired maimu stack size;
Stack create(int size);
void destroy(Stack s);

void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);

// we implemented "Item" type instead of hardcoded "int"
void push(Stack s, Item i);
Item pop(Stack s);

#endif