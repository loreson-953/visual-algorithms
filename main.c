#include <stdio.h>
#include "algorithms.h"

int main(void) {
	int array[] = {5, 2, 3, 6, 7};
	int length = sizeof(array) / sizeof(int);

	bubble_sort(array, length);
	
	return 0;
}
