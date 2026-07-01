/* Convert 12-hour time to 24-hour form*/

#include <stdio.h>
#include <ctype.h>

int main(void) {
    int hour;
    int minute;
    char pm_am;

    printf("Enter a 12-hour time (format: hour:minutes <pm/am>): ");

    scanf("%d :%d %c", &hour, &minute, &pm_am);

    if (toupper(pm_am) == 'P') {
        if (hour == 12) {
            ;
        } else {
            hour += 12;
        }
    } else if (toupper(pm_am) == 'A' && hour == 12) {
        hour -= 12;
    } 


    printf("Equivalent 24-hour time: %d:%d\n", hour, minute);

    return 0;
}
