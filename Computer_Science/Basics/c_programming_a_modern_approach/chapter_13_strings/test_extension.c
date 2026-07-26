/* test if file name matches extension */
/* The function should return true if file_name extension matches "extension".*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool test_extension(const char *file_name, const char *extension);

int main(void) {
    printf("%b\n", test_extension("test.txt.exe", "exe"));
    return 0;
}

bool test_extension(const char *file_name, const char *extension) {
    const char *ptr_last;
	while (*file_name++) {
        if (*file_name == '.') {
            ptr_last = file_name;
        }
    }

    if (*ptr_last == '.') {
        if (strcmp(ptr_last + 1, extension) == 0) {
            return true;
        }
    }
    return false;
}

