#include <stdio.h>
#include <stdlib.h>

#define F_NAME "file_to_open.txt"
int main(void) {
    printf("Print to the console\n");
    // redirect stdout to file_to_open.txt
    if (freopen("file_to_open.txt", "w", stdout) == NULL) {
        perror("Failed to redirect stdout");
        exit(EXIT_FAILURE);
    }
    printf("2. app start\n");
    printf("3. operation completed\n");

    // close stdout stream
    (void)fclose(stdout);
    return EXIT_SUCCESS;
}