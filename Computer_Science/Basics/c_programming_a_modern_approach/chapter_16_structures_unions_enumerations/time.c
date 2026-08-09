#include <stdio.h>

    typedef struct Time {
        int hours;
        int minutes;
        int seconds;
        } Time;

Time split_time (long total_seconds);


int main(void) {
    Time x = split_time(10000);
    printf("hours: %d\nminutes: %d\nseconds: %d\n",
            x.hours, x.minutes, x.seconds);
    return 0;
}

Time split_time (long total_seconds) {
    Time x = {
        .hours =  total_seconds / 3600,
        .minutes = (total_seconds % 3600) / 60,
        .seconds = (total_seconds % 3600) % 60,
    };
    return x;
}
