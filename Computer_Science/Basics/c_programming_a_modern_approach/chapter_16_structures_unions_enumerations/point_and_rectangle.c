#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
struct point {int x, y; };
struct rectangle { struct point upper_left, lower_right;};


int area(struct rectangle a);
struct point center(struct rectangle r);
struct rectangle move(struct rectangle r, int move_x, int move_y);
bool point_in_rectangle(struct rectangle r, struct point p);

int main(void) {
    struct rectangle x;

    x.lower_right.x = 3;
    x.lower_right.y = 1;
    x.upper_left.x = 1;
    x.upper_left.y = 3;
    printf("area: %d\n", area(x));
    struct point c = center(x);
    printf("center: x = %d, y = %d\n", c.x, c.y);
    printf("%d\n", point_in_rectangle(x, c));
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

struct rectangle move(struct rectangle r, int move_x, int move_y) {
    r.lower_right.x += move_x;
    r.upper_left.x += move_x;

    r.lower_right.y += move_y;
    r.upper_left.y += move_y;
    return r;
}

bool point_in_rectangle(struct rectangle r, struct point p) {
    if (p.x < MAX(r.lower_right.x, r.upper_left.x) && 
        p.x > MIN(r.lower_right.x, r.upper_left.x) &&
        p.y < MAX(r.lower_right.y, r.upper_left.y) &&
        p.y > MIN(r.lower_right.y, r.upper_left.y)) {
            return true;
        }
        return false;
}

