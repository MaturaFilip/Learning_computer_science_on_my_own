/*
void build_index_url(const char *domain, char *index_url);

Function should add "http://www." to the beginning of the string
and "/index.html" to the end of the string.
Hint: use strcat, strcpy
*/

#include <stdio.h>
#include <string.h>


void build_index_url(const char *domain, char *index_url);
void build_index_url_v2(const char *domain, char *index_url);


int main(void) {
    char domain[] = "knking.com";
    char index_url[50];
    build_index_url_v2(domain, index_url);
    printf("%s\n", index_url);
    return 0;
}

void build_index_url(const char *domain, char *index_url) {
    strcpy(index_url, "http://www.");

    // go to the end of the index_url (points after ".")
    while (*index_url) {
        //printf("%c\n", *index_url);
        index_url++;
    }

    strcat(index_url, domain);

    while(*index_url) {
        index_url++;
    }

    strcat(index_url, "/index.html");
	
}

// version 2
void build_index_url_v2(const char *domain, char *index_url) {
    strcat(strcat(strcpy(index_url, "http://www."), domain), "/index.html");
}
