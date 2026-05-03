#include <stdlib.h>
#include <ncurses.h>
#include "algorithms.h"
#include "ui.h"

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

int main(void) {

	WINDOW *title_window;

	window_info title_info;
	title_info.start_x = title_info.start_y = 0;
	title_info.height = 5;
	title_info.width = 100;
	char title_text[] = "Welcome to Visual Algorithms.";
	int title_text_length = sizeof(title_text) / sizeof(char);
	
	// User input initialization
	dynamic_array input;
	input.count = 0; 
	input.capacity = 10; // 10 is a decent place to start with
	input.number = malloc(input.capacity * sizeof(input.number));

	// Initialize ncurses
	ncurse_initialization();
	refresh();
	
	// Create and print to title window
	title_window = create_new_window(title_info.height, title_info.width, title_info.start_y, title_info.start_x);
	mvwprintw(title_window, title_info.height / 2, (title_info.width - title_text_length) / 2, title_text);
	wrefresh(title_window);
	
	getch();
	endwin();
	
	return 0;
}
