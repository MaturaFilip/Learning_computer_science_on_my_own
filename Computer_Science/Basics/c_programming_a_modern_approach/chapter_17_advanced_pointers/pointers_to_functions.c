#include <stdio.h>

int add(int a, int b);
int multiply(int a, int b);
//void compute(int x, int y, int (*op)(int, int));      // Old version
typedef int (*MathFunc)(int, int);
void compute(int x, int y, MathFunc op);    // now the function definition is little bit cleaner


int main(void) {
    compute(5, 5, add);
    compute(5, 5, multiply);
    return 0;
}

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

// Function that accepts a function pointer as an argument (similar to lambda)
void compute(int x, int y, MathFunc op) {
    int result = op(x, y);
    printf("Result: %d\n", result);
}