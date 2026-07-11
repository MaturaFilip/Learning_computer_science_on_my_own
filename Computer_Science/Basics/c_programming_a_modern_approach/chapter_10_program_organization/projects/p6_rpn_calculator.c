/* Implement RPN calculator */


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
int calculate(int r, int l, char operand);

/* external variables */
int contents[STACK_SIZE];
int top = 0;


int main(void) {
    char ch;
    while(1) {
    printf("Enter an RPN expression: ");

    ch = getchar();
    while (ch != '\n') {

        if (ch >= '0' && ch <= '9') {
            push(ch - '0');

        } else if (ch == '=') {
            int result = pop();
            printf("Result: %d\n", result);
            break;

        } else {
            int r = pop();
            int l = pop();

            if ((r >= 0 && r <= 9) || (l >= 0 && r <= 9)) {
                ;
            } else {
                printf("Not enough operands in expression. Terminating");
                exit(EXIT_FAILURE);
            }
            int temp_res = calculate(r, l, ch);
            push(temp_res);
            }

        ch = getchar();
    }
    }
    return 0;
}

int calculate(int r, int l, char operand) {
    if (operand == '/') {
        return l / r;
    } else if (operand == '*') {
        return l * r;
    } else if (operand == '+') {
        return l + r;
    } else if (operand == '-') {
        return l - r;
    } else {
        printf("Wrong operand. Terminating the program");
        exit(EXIT_FAILURE);
    }
}
//###################################
//##########    STACK     ###########
//###################################
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