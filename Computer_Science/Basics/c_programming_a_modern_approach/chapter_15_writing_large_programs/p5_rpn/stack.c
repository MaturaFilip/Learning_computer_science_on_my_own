#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"
#include <stdio.h>

void make_empty(void) {
    top = 0;
}

bool is_empty(void) {
    return top == 0;
}

bool is_full(void) {
    return top == STACK_SIZE;
}

void push(int ch) {
    if (is_full()) {
        printf("Stack overflow. Terminating program\n");
        exit(EXIT_FAILURE);
    } else {
        contents[top++] = ch;
    }
}

int pop(void) {
    if (is_empty()) {
        printf("Stack underflow. Terminating program\n");
        exit(EXIT_FAILURE);
    } else {
        return contents[--top];
    }
}