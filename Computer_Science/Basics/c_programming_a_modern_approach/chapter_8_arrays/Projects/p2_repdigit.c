/* Checks numbers for repeated digits and prints a table showing how many times each digit appears in the number */

#include <stdio.h>

#define LEN ((int) (sizeof(digit_counter) / sizeof(digit_counter[0])))

int main(void) {
    int digit_counter[10] = {0};
    int digit;
    long n;


    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;

        digit_counter[digit] += 1;

        n /= 10;
    }

    printf("%-15s", "Digit:");

    for (int i = 0; i < LEN; i++) {
        printf("%d  ", i);
    }
    printf("\n");

    printf("%-15s", "Occurrences: ");
    for (int i = 0; i < LEN; i++) {
        printf("%d  ", digit_counter[i]);
    }
    printf("\n");


    return 0;
}