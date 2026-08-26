#include <stdio.h>
#include "stackADT2.h"
/* Implement RPN calculator */
#include <stdbool.h>
#include <stdlib.h>

int calculate(int r, int l, char operand);

int main(void) {
    Stack s1;
    s1 = create(50);
    char ch;

    while(1) {
    printf("Enter an RPN expression: ");

    ch = getchar();
    while (ch != '\n') {

        if (ch >= '0' && ch <= '9') {
            push(s1, ch - '0');

        } else if (ch == '=') {
            int result = pop(s1);
            printf("Result: %d\n", result);
            break;

        } else {
            int r = pop(s1);
            int l = pop(s1);

            if ((r >= 0 && r <= 9) || (l >= 0 && r <= 9)) {
                ;
            } else {
                printf("Not enough operands in expression. Terminating");
                exit(EXIT_FAILURE);
            }
            int temp_res = calculate(r, l, ch);
            push(s1, temp_res);
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