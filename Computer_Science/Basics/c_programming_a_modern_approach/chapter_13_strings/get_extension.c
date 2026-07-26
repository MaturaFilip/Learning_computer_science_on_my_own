/* 
file_name points to a string containing a file name. Function store extension
of the file name (test.txt -> it saves "txt" in the string pointed to by extension)
If file name doesn't have extension, save emoty string (single null character)

Hint: you can use "strlen", "strcpy"
*/
#include <stdio.h>
#include <string.h>


void get_extension(const char *file_name, char *extension);

int main(void) {
    char file_name[] = "test.txt";
    char extensions[strlen(file_name)];

    get_extension(file_name, extensions);
    printf("%s\n", extensions);
    return 0;
}

void get_extension(const char *file_name, char *extension)
{
    const char *ptr_last;
	while (*file_name) {
        if (*file_name == '.') {
            ptr_last = file_name;
        }
        file_name++;
    }
    if (*ptr_last == '.') {
        strcpy(extension, ptr_last + 1);
    } else {
        strcpy(extension, "");
    }
}