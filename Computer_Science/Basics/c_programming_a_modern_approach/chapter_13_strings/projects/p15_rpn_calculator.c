/* Implement RPN calculator */

/*
    Implement function:
        int evaluate_RPN_expression(const char *expression);
*/


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int evaluate_RPN_expression(const char *expression);
int read_line(char str[], int n);

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
    char expression[STACK_SIZE];
    int res;

    printf("Enter an RPN expression: ");
    read_line(expression, STACK_SIZE);
    res = evaluate_RPN_expression(expression);
    printf("Result: %d", res);
 
    return 0;
}

int evaluate_RPN_expression(const char *expression) {
    while (*expression) {

        if (*expression >= '0' && *expression <= '9') {
            push(*expression - '0');

        } else if (*expression == '=') {
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
            int temp_res = calculate(r, l, *expression);
            push(temp_res);
            }

        //ch = getchar();
        expression++;
    }
}

int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';  /* terminates string */
    return i;   /* number of characters stored */
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