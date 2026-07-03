/* Checks numbers for repeated digits - p3 -> allow user to input more numbers, ale terminate when num <= 0 entered*/

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    bool digit_seen[10] = {false};
    int digit;
    long n;
    bool flag = false;


    while (1) {
        printf("Enter a number (0 to end the calculation): ");
        scanf("%ld", &n);

        if (n == 0 || n < 0) {
            break;
        }

        while (n > 0) {
            digit = n % 10;
            if (digit_seen[digit]) {
                flag = true;
            }
            digit_seen[digit] = true;
            n /= 10;
            }
        }

    if (flag) {
        printf("Repeated digit\n");
    } else {
        printf("No repeated digit\n");
    }
    return 0;
}