/* Checks numbers for repeated digits and if number is repeated, show it */

#include <stdbool.h>
#include <stdio.h>

#define LEN ((int) (sizeof(digit_repeated) / sizeof(digit_repeated[0])))

int main(void) {
    bool digit_seen[10] = {false};
    bool digit_repeated[10] = {false};
    bool flag = false;
    int digit;
    long n;


    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit]) {
            digit_repeated[digit] = true;
        }
        digit_seen[digit] = true;
        n /= 10;
    }
    printf("Repeated digit(s): ");
    for (int i = 0; i < LEN; i++) {
        if (digit_repeated[i]) {
            flag = true;
            printf("%d ", i);
        }
    }

    if (flag == false) {
        printf("No digit repeated");
    }
    printf("\n");
    return 0;
}