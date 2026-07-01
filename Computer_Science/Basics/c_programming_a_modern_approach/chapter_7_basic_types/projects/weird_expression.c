/* evaluate expression with 3 numbers with no precedence -> from left to right*/

#include <stdio.h>

double calculate(double num_1, double num_2, char operator) ;

int main(void) {
    double first, second, third;
    char operator_1, operator_2;
    double value;

    printf("Enter an expression: \n");

    scanf("%lf%c%lf%c%lf", &first, &operator_1, &second, &operator_2, &third);

    value = calculate(first, second, operator_1);
    value = calculate(value, third, operator_2);

    printf("Value of expression: %lf", value);
    return 0;
}


//1+2.5*3 = 10.5; operands are floats, operators are +, -, * and /
double calculate(double num_1, double num_2, char operator) {
    if (operator == '+') {
        return num_1 + num_2;
    } else if (operator == '-') {
        return num_1 - num_2;
    } else if (operator == '*') {
        return num_1 * num_2;
    } else {
        return num_1 / num_2;
    }
}