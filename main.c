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
	title_info.start_x = 4;
	title_info.start_y = 1;
	title_info.height = 5;
	title_info.width = 100;

	WINDOW *options_window;
	window_info options_info;
	options_info.start_x = title_info.start_x;
	options_info.start_y = title_info.height + 2;
	options_info.height = title_info.height + 3;
	options_info.width = title_info.width;
	 
	// User input initialization
	dynamic_array input;
	input.count = 0; 
	input.capacity = 10; // 10 is a decent place to start with
	input.number = malloc(input.capacity * sizeof(input.number));

	// Initialize ncurses
	ncurse_initialization();
	keypad(options_window, TRUE);
	refresh();
	
	// Create and print to title window
	title_window = create_new_window(title_info.height, title_info.width, title_info.start_y, title_info.start_x);
	mvwprintw(title_window, title_info.height / 2, (title_info.width - 30) / 2, "Welcome to Visual Algorithms.");
	wrefresh(title_window);

	options_window = create_new_window(options_info.height, options_info.width, options_info.start_y, options_info.start_x);
	mvwprintw(options_window, 2, 2, "Options:");
	wrefresh(options_window);
	mvwprintw(options_window, 4, 2, "1. Bubble Sort");
	wrefresh(options_window);
	mvwprintw(options_window, 5, 2, "0. Exit");
	wrefresh(options_window);
	
	getch();
	endwin();
	
	return 0;
}
