/* declare array with length 40 and fill it with fibonacii numbers */
#include <stdio.h>

#define LEN ((int) (sizeof(fib_numbers) / sizeof(fib_numbers[0])))

int main() {

    int fib_numbers[40] = {0, 1};

    for (int i = 2; i < LEN; i++) {
        fib_numbers[i] = fib_numbers[i - 2] + fib_numbers[i - 1];
    }

    for (int i = 0; i < LEN; i++) {
        printf("%d\n", fib_numbers[i]);
    }
    return 0;
}