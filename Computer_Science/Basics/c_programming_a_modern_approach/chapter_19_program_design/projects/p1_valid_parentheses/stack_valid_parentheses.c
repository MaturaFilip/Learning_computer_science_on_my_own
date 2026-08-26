#include <stdio.h>
#include "stackADT2.h"
#include <stdbool.h>
#include <stdlib.h>

int main(void) {
    Stack s1;
    char ch;
    s1 = create(50);
    printf("Enter parentheses and/or braces: ");

    ch = getchar();
    while (ch != '\n') {
        if (ch == '(' || ch == '{') {
            push(s1, ch);
        } else if (ch == ')' || ch == '}') {
            char check = pop(s1);
            if ((check == '(' && ch == ')') || (check == '{' && ch == '}')) {
                ;
            } else {
                printf("Parentheses/braces are NOT nested properly\n");
                return 1;
            }
        }
        ch = getchar();
    }

    if (is_empty(s1)) {
        printf("Parentheses/braces are nested properly\n");
    } else {
        printf("Parentheses/braces are NOT nested properly\n");
    }
    return 0;
}