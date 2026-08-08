#include <stdio.h>

    typedef struct Date {
        int month;
        int day;
        int year;
        } Date;

int day_of_year(Date d);
int compare_dates(Date d1, Date d2);

int main(void) {
    Date x = {.month = 2,
              .day = 20,
              .year = 2026};
    Date y = {.month = 2,
              .day = 20,
              .year = 2026};

    int bla = day_of_year(x);
    printf("%d\n", bla);
    printf("\n");

    printf("compare_date = %d\n", compare_dates(x,y));
    return 0;
}

int day_of_year(Date d) {
    int days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int counter = 0;
    if ((d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0)) {
        // lap year
        days_per_month[1] += 1;
    }
    // 1 
    for (int i = 0; i < (d.month - 1); i++) {
        counter += days_per_month[i];
    }
    counter += d.day;
    return counter;
}

int compare_dates(Date d1, Date d2) {
    int d_1 = day_of_year(d1);
    int d_2 = day_of_year(d2);

    if (d_1 < d_2) {
        return -1;
    } else if (d_1 > d_2) {
        return 1;
    } else {
        return 0;
    }
}