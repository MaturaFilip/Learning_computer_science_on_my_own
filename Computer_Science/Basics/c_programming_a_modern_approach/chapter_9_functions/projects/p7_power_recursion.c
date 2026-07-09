/* computer x^n with recursion */

#include <stdio.h>

int power(int x, int n);

int main(void) {
	int x, n;

	printf("Enter a value for x and n (e.g: 5 2) ");
	scanf("%d %d", &x, &n);

    printf("%d power to %d is: %d\n", x, n, power(x, n));
    return 0;
}

int power(int x, int n) {
    int i;

    if (n == 0)
        return 1;

    if (n % 2 == 0) {
        i = power(x, n / 2);
        return i * i;
    } else 
        return x * power(x, n - 1);
}