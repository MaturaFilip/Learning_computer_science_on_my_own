/******************************************************************************

                            Online C Debugger.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Debug" button to debug program.

*******************************************************************************/

#include <stdio.h>
double tax_calc(double income);
int main()
{
    double income;
    
	printf("Enter the taxable income: ");
	scanf("%lf", &income);
	
	printf("Tax due = %f\n", tax_calc(income));

    return 0;
}

double tax_calc(double income) {
    if (income < 750) {
        return 0.01f * 750;
    } else if (income < 2250) {
        return (7.5f + (0.02f * (income - 750)));
    } else if (income < 3750) {
        return (37.5f + (0.03f * (income - 2250)));
    } else if (income < 5250) {
        return (82.5f + (0.04f * (income - 3750)));
    } else if (income < 7000) {
        return (142.5f + (0.05f * (income - 5250)));
    } else {
        return (230.0f + (0.06f * (income - 7000)));
    }
}
