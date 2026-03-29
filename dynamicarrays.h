#ifndef DYNAMICARRAYS_H
#define DYNAMICARRAYS_H

#include <stdlib.h>

typedef struct {
	int rows;
	int columns;
	int **data;
} dynamic_array;

dynamic_array create_array(int rows, int columns);
dynamic_array free_array(dynamic_array output);

#endif
