#ifndef QUICKSORT_H
#define QUICKSORT_H

// quicksort main recursive call
void quicksort(int a[], int *low, int *high);

// set pivot and rearange the array in way that pivot is 
// in the middle of the array/sub-array, lower values to
// the left of the array and higher value in the right side
int *split(int a[], int *low, int *high);
#endif