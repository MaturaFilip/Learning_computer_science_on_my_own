#include <stdio.h>
#include <stdlib.h>
struct point {int x, y; };
struct rectangle { struct point upper_left, lower_right;};


int area(struct rectangle a);
struct point center(struct rectangle r);
struct point move(struct rectangle r, int move_x, int move_y);

int main(void) {
    struct rectangle x;

    x.lower_right.x = 3;
    x.lower_right.y = 1;
    x.upper_left.x = 1;
    x.upper_left.y = 3;
    printf("area: %d\n", area(x));
    struct point c = center(x);
    printf("center: x = %d, y = %d\n", c.x, c.y);
    return 0;
}

int area(struct rectangle r) {
    return (abs((r.lower_right.x - r.upper_left.x)) *
           abs((r.upper_left.y - r.lower_right.y)));
}

struct point center(struct rectangle r) {
	return (struct point) {(r.upper_left.x + r.lower_right.x) / 2,
	                      (r.lower_right.y + r.upper_left.y) / 2};
}

struct point move(struct rectangle r, int move_x, int move_y) {
    ;
}

