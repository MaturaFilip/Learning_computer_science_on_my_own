/* Have it leave behind characters that it doesn't have room to store */
#include <ctype.h>
#include <stdio.h>
int read_line(char str[], int n);

#define STR_LEN 4
int main(void) {

    char message[STR_LEN - 1];
    read_line(message, STR_LEN - 1);
    printf("%s\n", message);
}
/*
Consequence: The next time you call getchar() or read from stdin,
 you will read the leftover characters from the previous line rather than waiting for new user input.
 char 4 -> previous function doggoid -> dogg (flush remaining); function below -> dogg (left oid)
*/
/* in previous: while normally continues till '\n', so next time you use getchar, it will be from scratch again*/
int read_line(char str[], int n)
{
  int ch, i;

  for (i = 0; i < n; i++) {
    ch = getchar();
    if (ch == '\n') {
      break;
    }
    str[i] = ch;
  }
  str[i] = '\0';
  return i;
}