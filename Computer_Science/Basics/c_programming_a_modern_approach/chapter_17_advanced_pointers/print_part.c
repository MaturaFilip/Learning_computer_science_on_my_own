#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

void print_part(struct part *p);

int main(void) {
    struct part part1 = {
                        .number = 10,
                        .name = "kekel",
                        .on_hand = 20,
    };
    print_part(&part1);
    return 0;
}

void print_part(struct part *p) {
    printf("Part number: %d\n", p->number);
    printf("Part name: %s\n", p->name);
    printf("Quantity on hand: %d\n", p->on_hand);
}