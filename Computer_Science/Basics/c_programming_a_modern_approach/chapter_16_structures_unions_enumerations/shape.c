#include <stdio.h>

enum s {RECTANGLE, CIRCLE};
struct point { int x, y; };
struct shape {
	int shape_kind;    // RECTANGLE or CIRCLE
	struct point center;	// coordinates of center
	union {
		struct {
			int height;
			int width;
		} rectangle;
		
		struct {
			int radius;
		} circle;
	} u;
} s;

int area(struct shape s);
struct shape move(struct shape s, int move_x, int move_y);
struct shape scale(struct shape s, double c);

int main(void) {
    s.shape_kind = RECTANGLE;
    s.u.rectangle.height = 10;
    s.u.rectangle.width = 20;
    printf("area: %d\n", area(s));
    printf("area after scale %d\n", area(scale(s, 2)));
    return 0;
}

int area(struct shape s) {
    if (s.shape_kind == RECTANGLE) {
        return (s.u.rectangle.height * s.u.rectangle.width);
    }
    
    if (s.shape_kind == CIRCLE) {
        return (3.14159 * s.u.circle.radius * s.u.circle.radius);
    }
}

struct shape move(struct shape s, int move_x, int move_y) {
    s.center.x += move_x;
    s.center.y += move_y;
    return s;
}

struct shape scale(struct shape s, double c) {
    if (s.shape_kind == RECTANGLE) {
        s.u.rectangle.height *= c;
        s.u.rectangle.width *= c;
        return s;
    }
    
    if (s.shape_kind == CIRCLE) {
        s.u.circle.radius *= c;
        return s;
    }
}