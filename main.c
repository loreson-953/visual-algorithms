#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int *number;
	size_t count;
	size_t capacity;
} dynamic_array;

#define append_array(array, input)\
do {\
	if (array.count >= array.capacity) {\
		array.capacity += sizeof(int);\
		array.number = realloc(array.number, array.capacity * sizeof(array.number));\
	}\
	array.number[array.count++] = input;\
 } while(0)

void print_array(int array[], int length);

	/*
int* merge_sort(int array[], int length);
int* merge_sort_recursion(int array[], int left, int right);
int* merge_sorted_arrays(int array[], int left, int midpoint, int right);
	*/

void bubble_sort(int array[], int length);


int main(void) {

	dynamic_array input;
	input.count = 0;
	input.capacity = 10;
	input.number = malloc(input.capacity * sizeof(input.number));

	size_t num;
	int length = 0;
	int choice;
	
	
	printf("Please input positive integers you wish to sort.\n");
	printf("When you are done, input -1.\n");
	scanf("%zu", &num);
	while (num != -1) {
		length++;
		append_array(input, num);
		scanf("%zu", & num);
	}

	printf("\nWhich sorting algorithm do you want to use?\n");
	printf("Input a number to make your choice.\n");
	printf("0. Exit\n");
	printf("1. Bubble Sort\n");
	scanf("%d", &choice);

	while (choice != 0) {
		if (choice == 1) {
			printf("Your original array:\n");
			print_array(input.number, length);
		}
			
		switch (choice) {
		case 1:
			bubble_sort(input.number, length);
			choice = 99;
			break;
		case 99:
			break;
		default:
			printf("That is not a choice.\n");
			choice = 99;
			break;
		}

		printf("Make another choice or exit.\n");
		scanf("%d", &choice);
	}

	free(input.number);
	
	return 0;		
}

void print_array(int array[], int length) {
		for (int i = 0; i < length; i++)
		printf("%d ", array[i]);
	printf("\n");

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



// Bubble

void bubble_sort(int array[], int length) {

	// Create and initialize our array
	dynamic_array output;
	output.capacity = 10;
	output.count = 0;
	output.number = malloc(output.capacity * sizeof(int));

	// Initial copy of original array
	for (int i = 0; i < length -1; i++)
		append_array(output, array[i]);
	
	for (int i = 0; i < length - 1; i++) {
		int temp = 0;
		
		for (int j = 0; j < length - i - 1; j++) {
			

			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				// Copy the contents of the step
				for (int k = 0; k < length - 1; k++)
					append_array(output, array[k]);		
			}	
		}		
	}

	for (int i = 0; i < output.count; i++)
		printf("%d ", output.number[i]);
	printf("\n");

	free(output.number);
}

