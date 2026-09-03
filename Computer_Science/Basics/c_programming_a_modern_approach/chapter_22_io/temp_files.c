#include <stdio.h>
#include <unistd.h>

int main(void) {
    FILE* tempptr;

    tempptr = tmpfile();
    sleep(5);
    return 0;
}