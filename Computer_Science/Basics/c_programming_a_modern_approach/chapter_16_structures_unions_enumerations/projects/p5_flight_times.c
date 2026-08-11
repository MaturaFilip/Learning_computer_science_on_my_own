#include <stdio.h>


struct flights {
    int arrival;
    int departure;
};

#include <stdio.h>
#include <stdlib.h>

#define LEN ((int) (sizeof(f) / sizeof(f[0])))

#define MINUTE 60
int main(void) {
    struct flights f[8] = 

    {
        {8 * MINUTE, 10 * MINUTE + 16},
        {9 * MINUTE + 43, 11 * MINUTE + 52},
        {11 * MINUTE + 19, 13 * MINUTE + 31},
        {12 * MINUTE + 47, 15 * MINUTE},
        {14 * MINUTE, 16 * MINUTE + 8},
        {15 * MINUTE + 45, 17 * MINUTE + 55},
        {19 * MINUTE, 21 * MINUTE + 20},
        {21 * MINUTE + 45, 23 * MINUTE + 58},
    };
 
    int user_time,
        hour,
        minute,
        closest_time = 24 * MINUTE,
        arr_closes_time;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hour, &minute);
    user_time = hour * 60 + minute;

    printf("Closest departure time is ");

    for (int i = 0; i < LEN; i++) {
        if (abs(user_time - f[i].arrival) < closest_time) {
            closest_time = abs(user_time - f[i].arrival);
            arr_closes_time = i;
        }
    }

    int arr_hour = f[arr_closes_time].arrival / 60;
    int arr_minute = f[arr_closes_time].arrival - (arr_hour * 60);

    int dep_hour = f[arr_closes_time].departure / 60;
    int dep_minute = f[arr_closes_time].departure - (dep_hour * 60);
    printf("%d:%d, arriving at %d:%d\n", arr_hour, arr_minute, dep_hour, dep_minute);
    return 0;
}