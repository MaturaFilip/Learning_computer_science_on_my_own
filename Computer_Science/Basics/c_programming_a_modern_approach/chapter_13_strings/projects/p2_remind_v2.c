/* Prints a one-month reminder list */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50   /* Maximum number of reminder */
#define MSG_LEN 60  /* max length of reminder message */

int read_line(char str[], int n);

int main(void) {
    // 50x60 array
    char reminders[MAX_REMIND][MSG_LEN + 3];

    // day + message
    char day_str[20], hour_str[10], msg_str[MSG_LEN + 1];

    // counters
    int month, day, hour, i, j, num_remind = 0;


    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day, hour (24h format) and reminder: ");
        // 2d -> take only two digit number
        scanf("%d/ %2d", &month, &day);

        if (day == 0 || month == 0) {
            break;
        }

        // save string to day_str from day variable
        sprintf(day_str, "%4.2d %4.2d", month, day);
        scanf("%2d", &hour);
        sprintf(hour_str, "%4.2d", hour);

        // read reminder
        read_line(msg_str, MSG_LEN);

        if (day > 31 || day < 0) {
            printf("Day can't be less than 0 or larger than 31\n");
            continue;
        }
        // 23 10 pes
        // 15 11 pes
        // 15 < reminders, so i = 0
        for (i = 0; i < num_remind; i++) {
            if (strcmp(day_str, reminders[i]) < 0) {
                break;
            }
        }
        // num_remind = 1 and i = 0
        // copy 23 pes to row 1
        // 15 pes then will be copy to row 0
        for (j = num_remind; j > i; j--) {
            strcpy(reminders[j], reminders[j-1]);
        }



        // add entered string to reminders array

        strcpy(reminders[i], day_str);
        strcat(reminders[i], "");
        strcat(reminders[i], hour_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }


    printf("\nMonth Day Hour Reminder\n");
    for (i = 0; i < num_remind; i++) {
        printf(" %s\n", reminders[i]);
    }

    return 0;
}

// did not trim or create space between day and reminder
int read_line(char str[], int n) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n') {
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}