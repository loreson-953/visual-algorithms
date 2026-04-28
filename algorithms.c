#include <stdio.h>
#include "algorithms.h"

void bubble_sort(int array[], int length) {	
	// for (int k = 0; k < length; k++) printf("%d ", array[k]);
	// printf("\n");
	
	for (int i = 0; i < length - 1; i++) {
		int temp = 0;
		
		
		for (int j = 0; j < length - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}	

			// Debugging lines
			// for (int k = 0; k < length; k++) printf("%d ", array[k]);
			// printf("\n");
		}		
	}
}
