/* Project 1: Smallest number of bills */
/* enter a dollar amount and how to pay with $20, $10, $5, $1 with smallest number*/

#include <stdio.h>

void pay_amount (int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void)
{   int dollars, twenties, tens, fives, ones;

	//int usd_amount, remainder, bills;

	printf("Enter a dollar amount: ");
	scanf("%d", &dollars);

    pay_amount(dollars, &twenties, &tens, &fives, &ones);

	printf("20$ bills: %d\n", twenties);
	printf("10$ bills: %d\n", tens);
	printf("5$ bills: %d\n", fives);
	printf("$ bills: %d\n", ones);
}

void pay_amount (int dollars, int *twenties, int *tens, int *fives, int *ones) {
    *twenties = dollars / 20;

    int remainder = dollars - *twenties * 20;

    *tens = remainder / 10;

    remainder = remainder - *tens * 10;

    *fives = remainder / 5;

    remainder = remainder - *fives * 5;

    *ones = remainder;
}