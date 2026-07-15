#include <stdio.h>
#include <stdlib.h>

void split_date(int day_of_year, int year, int *month, int *day);

int main(void) {

    int day_of_year = 1, year = 2026, month, day;
    split_date(day_of_year, year, &month, &day);
    printf("day of the year: %d, year: %d, month: %d, day: %d\n", day_of_year, year, month, day);
    return 0;
}

void split_date(int day_of_year, int year, int *month, int *day) {
    int days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    *month = 1;

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        // lap year
        days_per_month[1] += 1;
    }

    for (int i = 0; i < 12; i++) {
        if(day_of_year > days_per_month[i]) {
            *month += 1;
            day_of_year -= days_per_month[i];
        } else {
            break;
        }
    }
    *day = day_of_year;
}