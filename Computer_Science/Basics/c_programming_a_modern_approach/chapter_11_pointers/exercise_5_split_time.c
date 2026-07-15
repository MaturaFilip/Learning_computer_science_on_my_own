#include <stdio.h>
#include <stdlib.h>

void split_time(long total_sec, int *hr, int *min, int *sec);

int main(void) {
    long total_sec = 2847;
    int hr, min, sec;


    split_time(total_sec, &hr, &min, &sec);

    printf("Second since midnight: %ld\n", total_sec);
    printf("Transformed %ld seconds to hours, min, sec\n", total_sec);
    printf("hours: %d, minutes %d, seconds: %d\n", hr, min, sec);

    return 0;
}

void split_time(long total_sec, int *hr, int *min, int *sec) {
    if (total_sec > 86400) {
        printf("More than 24 hours after midnight, terminating");
        exit(1);
    }
    *hr = total_sec / 3600;
    *min = (total_sec / 60) % 60;
    *sec = total_sec % 60;
}