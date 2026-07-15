/* modeify departure times project to include find_closest_flight function */
/* User enter time and program finds the closest departure time (from the array) to the user time */
#include <stdio.h>
#include <stdlib.h>

#define LEN ((int) (sizeof(arr) / sizeof(arr[0])))

#define MINUTE 60

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main(void) {

    int user_time, hour, minute;
    int departure_time, arrival_time;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hour, &minute);

    // convert to minutes
    user_time = hour * 60 + minute;
    find_closest_flight(user_time, &departure_time, &arrival_time);
    printf("Closest departure time is ");
    printf("%d:%d, arriving at %d:%d\n", (departure_time / 60),
                                         (departure_time % 60),
                                         (arrival_time / 60),
                                         (arrival_time % 60));
    return 0;
}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time) {
    int closest_time = 24 * MINUTE;
    int dep_closes_time;
    int dep[8] = {8 * MINUTE, 9 * MINUTE + 43, 11 * MINUTE + 19, 12 * MINUTE + 47, 14 * MINUTE, 15 * MINUTE + 45, 19 * MINUTE, 21 * MINUTE + 45 };
    int arr[8] = {10 * MINUTE + 16, 11 * MINUTE + 52, 13 * MINUTE + 31, 15 * MINUTE, 16 * MINUTE + 8, 17 * MINUTE + 55, 21 * MINUTE + 20, 23 * MINUTE + 58};

    for (int i = 0; i < LEN; i++) {
        if ((abs(desired_time - dep[i])) < closest_time) {
            closest_time = abs(desired_time - dep[i]);
            dep_closes_time = i;
        }
    }

    *arrival_time = arr[dep_closes_time]; //- (arr_hour * 60);
    *departure_time = dep[dep_closes_time];// - (dep_hour * 60);
}