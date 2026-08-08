#include <stdio.h>
#include <string.h>
#define NAME_LEN 20

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    };

void print_part(struct part x);
struct part build_part(int number, const char *name, int on_hand);

int main(void) {


    struct part x = {10, "dog", 1};
    print_part(x);


    print_part(build_part(1, "hello", 2));
    return 0;    
}

void print_part(struct part x) {
    printf("%d - %s - %d\n", x.number, x.name, x.on_hand);
}

// return struct

struct part build_part(int number, const char *name, int on_hand) {
    struct part p;

    p.number = number;
    strcpy(p.name, name);
    p.on_hand = on_hand;
    return p;
}
