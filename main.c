#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int *number;
	size_t count;
	size_t row;
	size_t column;
	size_t capacity;
} dynamic_array;

#define append_array(array, input)\
do {\
	if (array.count >= array.capacity) {\
		array.capacity += sizeof(int);\
		array.number = realloc(array.number, array.capacity * sizeof(array.number));\
	}\
	array.number[test.count++] = input;\
 } while(0)

	/*
int* merge_sort(int array[], int length);
int* merge_sort_recursion(int array[], int left, int right);
int* merge_sorted_arrays(int array[], int left, int midpoint, int right);

int* bubble_sort(int array[], int length);
*/

int main(void) {

	int input = 0;
	dynamic_array test;
	test.capacity = 10;
	test.row = 0;
	test.number = malloc(test.capacity * sizeof(int));
	
	
	printf("Give me some numbers.\n");
	scanf("%d", &input);
	
	while (input != -1) {
		append_array(test, input);
		scanf("%d", &input);
	}

	for (size_t i = 0; i < test.count; i++)
		printf("%d\n", test.number[i]);
		
	return 0;		
}

/*

// Merge 
int* merge_sort(int array[], int length) { 
	dynamic_array output = {0};
	
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

*/

/*

// Bubble

int* bubble_sort(int array[], int length) {

	// Create and initialize our array
	dynamic_array output;
	output.capacity = 10;
	output.count = 0;
	output.number = malloc(output.capacity * sizeof(int));
	
	for (int i = 0; i < length - 1; i++) {
		int temp = 0;
		
		for (int j = 0; j < length - i - 1; j++) {
			

			if (array[j] > array[j + 1]) {
				if (output.count >= output.capacity) {
					output.capacity += sizeof(int);
					output.number = realloc(output.number, output.capacity * sizeof(output.number));
				}

				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				
			}

			
		}

		
	}	
	printf("%d\n", size);

	return &output;
}

*/
