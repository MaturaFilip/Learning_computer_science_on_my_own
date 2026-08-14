#include <stdio.h>


int sum(int (*f) (int),
        int start, int end);
int g(int x);

int main(void) {
	printf("Sum: %d\n", sum(g, 0, 5));
	return 0;
}

int sum(int (*f) (int),
        int start, int end) {

    int counter = 0;

    for (; start <= end; start++) {
        counter += f(start);
    }
    return counter;
}

int g(int x) {
    return x * x;
}