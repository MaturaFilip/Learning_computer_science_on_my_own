/*
void remove_filename(char *url);

url = "http://knking.com/index.html"
Function should remove the file name and the preceding shlash
result: http://knking.com
Incorporate "search for the end of a string" idiom
Hint: replace the last slash in the string by a null character \0
*/


#include <stdio.h>
#include <string.h>



void build_index_url(char *domain);

int main(void) {
    char domain[] = "http://knking.com/index.html";
    char index_url[50];
    build_index_url(domain);
    printf("%s\n", domain);
    //while (*index_url != '\0') {
    //    printf("kek\n");
    //}
    return 0;
}

// in-place implementation
void build_index_url(char *domain) {
    char *ptr_last;
    while (*domain) {
        if (*domain == '/') {
            ptr_last = domain;
        }
        domain++;
    }
    *ptr_last = '\0';
}

