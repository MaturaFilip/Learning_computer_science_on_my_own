#include <stdio.h>
#include "queue.h"

int main(void) {
    Queue q1, q2;
    int n;

    q1 = create();
    q2 = create();

    enqueue(q1, 1);
    enqueue(q1, 2);

    n = dequeue(q1);

    printf("Dequeue %d from q1\n", n);

    enqueue(q2, n);
    n = dequeue(q1);

    printf("Dequeue %d from s1\n", n);
    enqueue(q2, n);

    destroy(q1);

    while (!is_empty(q2)) {
        printf("Dequeue %d from q2\n", dequeue(q2));
    }

    enqueue(q2, 3);
    make_empty(q2);

    if (is_empty(q2)) {
        printf("s2 is empty\n");
    } else {
        printf("s2 is not empty\n");
    }

    destroy(q2);

    return 0;
}