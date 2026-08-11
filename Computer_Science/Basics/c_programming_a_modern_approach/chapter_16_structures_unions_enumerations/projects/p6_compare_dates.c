/* Comparing dates */

#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};

int main(void)
{
	int earlier_date = 0;
    struct date x, y;

	printf("Enter first date (mm/dd/yy): ");
	scanf(" %d / %d / %d", &x.month, &x.day, &x.year);

	printf("Enter second date (mm/dd/yy): ");
	scanf(" %d / %d / %d", &y.month, &y.day, &y.year);

	if(x.year < y.year)
		earlier_date = 1;
	else if(x.year > y.year)
		earlier_date = 2;
	else
	{
		if(x.month < y.month)
			earlier_date = 1;
		else if(x.month > y.month)
			earlier_date = 2;
		else
		{
			if(x.day < y.day)
				earlier_date = 1;
			else if(x.day > y.day)
				earlier_date = 2;
		}
	}

	if(earlier_date == 1)
	{
		printf("%d/%d/%02d is earlier than %d/%d/%02d\n", x.month, x.day, x.year, y.month, y.day, y.year);
	}
	else if(earlier_date == 2)
	{
		printf("%d/%d/%02d is earlier than %d/%d/%02d\n", y.month, y.day, y.year, x.month, x.day, x.year);
	}
	else
	{
		printf("Dates are same\n");
	}
	return 0;
}