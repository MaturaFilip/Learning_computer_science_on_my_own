/*
    user input: date with format mm/dd/yyyy
    output: display date in format mm/dd/yyyy but the 
        month will be name, not number of the month

    Store the months names in an array that contains pointers to strings
*/

#include <stdio.h>

int main(void) {
    char *months[] = {"January", "February", "March", "April", "May",
                      "June", "July" "August", "September", "October",
                      "November", "December"};
    
    int day, month, year;
    printf("Enter a dat (mm/dd/yyyy): ");
    scanf("%2d/%d/%4d", &month, &day, &year);

    if (day < 0 || day > 31 || month < 0 || month > 12) {
        printf("Wrong date intput\n");
        return 1;
    }
    printf("You entered the date %s %d, %d\n", months[month - 1], day, year);
    return 0;
}