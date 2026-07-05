#include <stdio.h>
#include <stdlib.h>

#define LEN ((int) (sizeof(arr) / sizeof(arr[0])))

#define MINUTE 60
int main(void) {
    int arr[8] = {8 * MINUTE, 9 * MINUTE + 43, 11 * MINUTE + 19, 12 * MINUTE + 47, 14 * MINUTE, 15 * MINUTE + 45, 19 * MINUTE, 21 * MINUTE + 45 };
    int dep[8] = {10 * MINUTE + 16, 11 * MINUTE + 52, 13 * MINUTE + 31, 15 * MINUTE, 16 * MINUTE + 8, 17 * MINUTE + 55, 21 * MINUTE + 20, 23 * MINUTE + 58};
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
        if (abs(user_time - arr[i]) < closest_time) {
            closest_time = abs(user_time - arr[i]);
            arr_closes_time = i;
        }
    }

    int arr_hour = arr[arr_closes_time] / 60;
    int arr_minute = arr[arr_closes_time] - (arr_hour * 60);

    int dep_hour = dep[arr_closes_time] / 60;
    int dep_minute = dep[arr_closes_time] - (dep_hour * 60);
    printf("%d:%d, arriving at %d:%d\n", arr_hour, arr_minute, dep_hour, dep_minute);
    return 0;
}