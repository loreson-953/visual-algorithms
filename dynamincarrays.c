#include "dynamicarrays.h"
#include <stdio.h>

dynamic_array create_arrray(int rows, int columns) {
	dynamic_array output;
	output.rows = rows;
	output.columns = columns;

	output.data = (int**)malloc(rows * sizeof(int*));
	if (array.data == NULL) {
		printf("Memory allocation for rows failed.\n");
	}
}
