#include "algorithms.h"

// Merge 

int* merge_sort(int array[], int length) { 
	merge_sort_recursion(array, 0, length - 1);
}

int* merge_sort_recursion(int array[], int left, int right) { 
 	if (left < right) { 
 		int midpoint = left + (right - left) / 2; 

			merge_sort_recursion(array, left, midpoint); 
			merge_sort_recursion(array, midpoint + 1, right); 

			merge_sorted_arrays(array, left, midpoint, right); 
	}
}

int* merge_sorted_arrays(int array[], int left, int midpoint, int right) {
	int left_length = midpoint - left + 1;
	int right_length = right - midpoint;
	int temp_left[left_length];
	int temp_right[right_length];

	int i, j, k;
	
	for (i = 0; i < left_length; i++)
		temp_left[i] = array[left + i];
	for (i = 0; i < left_length; i++)
		temp_right[i] = array[midpoint + 1 + i];

	for (i = 0, j = 0, k = left; k <= right; k++) {
		if ((i < left_length) &&
			(j >= right_length || temp_left[i] <= temp_right[j])) {
			array[k] = temp_left[i];
			i++;
		} else {
			array[k] = temp_right[j];
			j++;
		}
	}
}

// Bubble

int* bubble_sort(int array[], int length) {
	int **output;
	
	for (int i = 0; i < length - 1; i++) {
		int temp = 0;

		for (int j = 0; j < length - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}
