#include <stdio.h>

int main(void) {

    double num = 0.0, total = 0.0;
    char c;

    printf("Enter an expression: ");
    // get expression
    // -> first get number, other will go down
    scanf("%lf", &total);

    // statement above got the number, not c get the expression
    while ((c = getchar()) != '\n') {
        switch (c) {
            case '+':
                // after char another numeric -> calculation
                scanf("%lf", &num);
                total += num;
                break;
            case '-':
                scanf("%lf", &num);
                total -= num;
                break;
            case '*':
                scanf("%lf", &num);
                total *= num;
                break;
            case '/':
                scanf("%lf", &num);
                total /= num;
                break;
            default: 
                break;
        }
    }

    printf("Value of expression: %f\n", total);
    return 0;
}