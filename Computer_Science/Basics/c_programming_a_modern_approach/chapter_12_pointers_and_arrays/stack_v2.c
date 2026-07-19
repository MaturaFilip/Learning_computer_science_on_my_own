/* User enter parentheses or braces and program with stack implementation show if the () or {} are nested correctly*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
char pop(void);

/* external variables */
int contents[STACK_SIZE];
int top = 0;
int *top_ptr = &contents[0];


int main(void) {
    char ch;
    printf("Enter parentheses and/or braces: ");

    ch = getchar();
    while (ch != '\n') {
        // SOMETHING
        if (ch == '(' || ch == '{') {
            push(ch);
        } else if (ch == ')' || ch == '}') {
            char check = pop();
            if ((check == '(' && ch == ')') || (check == '{' && ch == '}')) {
                ;
            } else {
                printf("Parentheses/braces are NOT nested properly\n");
                return 1;
            }
        }
        ch = getchar();
    }

    if (is_empty) {
        printf("Parentheses/braces are nested properly\n");
    } else {
        printf("Parentheses/braces are NOT nested properly\n");
    }
    return 0;
}

void make_empty(void) {
    top_ptr = &contents[0];
}

bool is_empty(void) {
    return top_ptr == &contents[0];
}

bool is_full(void) {
    return top_ptr == &contents[STACK_SIZE ];
}

void push(int i) {
    if (is_full()) {
        printf("Stack overflow. Terminating program\n");
        exit(EXIT_FAILURE);
    } else {
        *top_ptr = i;
    }
}

char pop(void) {
    if (is_empty()) {
        printf("Stack underflow. Terminating program\n");
        exit(EXIT_FAILURE);
    } else {
        return *--top_ptr;
    }
}