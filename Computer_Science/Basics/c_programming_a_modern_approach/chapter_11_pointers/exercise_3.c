#include <stdio.h>

void avg_sum(int n, double a[n], double *avg, double *sum);

int main(void) {
    double sum = 0;
    double avg;

    int n = 5;
    double a[5] = {1, 2, 3, 4, 5};
    avg_sum(n, a, &avg, &sum);

    printf("sum = %lf, avg = %lf\n", sum, avg);
    return 0;
}

void avg_sum(int n, double a[n], double *avg, double *sum) {
    
    for (int i = 0; i < n; i++) {
        *sum += a[i];
    }
    *avg = *sum / n;
}