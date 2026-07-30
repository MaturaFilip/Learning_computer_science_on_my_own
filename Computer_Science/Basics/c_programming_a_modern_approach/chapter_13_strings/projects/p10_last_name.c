/* Enter first name and last name and display last name, comma and first letter of first name*/
/*
    Implement function below:
        void reverse_name (char *name);
    Function expect string: "first_name last_name" (it can contain spaces before, between or after string)
    Function should modify the string
*/
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define FULL_NAME_LEN 50
#define NAME_LEN 25

void reverse_name (char *name);
int read_line(char str[], int n);
void trim(char *s);

int main(void) {
    char name[FULL_NAME_LEN];
    printf("Enter a first and last name: ");
    read_line(name, FULL_NAME_LEN);
    reverse_name(name);
    return 0;
}

void reverse_name (char *name) {
    char first_name[NAME_LEN];
    char last_name[NAME_LEN];
    char *p = first_name, *q = last_name;
    bool first = true;
    // trim leading white-space
    trim(name);
    while (*name) {

        if (!isalpha(*name)) {
            first = false;
        }

        if (first) {
            *p = *name;
            p++;
        }

        if (!first && isalpha(*name)) {
            *q = *name;
            q++;
        }
        name++;
    }
    *p = '\0';
    *q = '\0';

    printf("%s, %c.\n", last_name, first_name[0]);
}

int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';  /* terminates string */
    return i;   /* number of characters stored */
}

void trim(char *s) {
    int i = 0, j = 0;

    while(s[i] == ' ') {i++;};
    while(s[j++] = s[i++]);
}