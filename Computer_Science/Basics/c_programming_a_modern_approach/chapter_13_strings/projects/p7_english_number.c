/*
	Enter two digit number and translate it to english
	e.g. 99 -> ninety-nine
	use pointers to strings instead of switch statements.
	e.g. 
*/
#include <stdio.h>

int main(void) {
	char *tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	char *units[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char *tn[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	int num, t, u;

	

	printf("Enter a two-digit number: ");
	scanf("%d", &num);

	t = num / 10;
	u = num % 10;
	printf("%d - %d\n", t, u);
	printf("You entered the number ");

	if(num == 0) {
		printf("zero");
	} else if(num >= 10 && num <= 19) {
		printf("%s", tn[num - 10]);
	} else if (num > 0 && num < 10) {
		printf("%s", units[u - 1]);
	} else {
		printf("%s-%s", tens[t - 2], units[u - 1]);
	}

	printf(".\n");

	return 0;
}