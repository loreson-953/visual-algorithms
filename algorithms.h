#ifndef ALGORITHMS_H
#define ALGORITHMS_H

// We need a global dynamic array
extern int output[];

// Merge

void merge_sort(int array[], int length);
void merge_sort_recursion(int array[], int left, int right);
void merge_sorted_arrays(int array[], int left, int midpoint, int right);

// Bubble

void bubble_sort(int array[], int length);

#endif
