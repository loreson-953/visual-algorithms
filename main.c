#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int startx = 0;
int starty = 0;

int main(void) {

	// User input initialization
	dynamic_array input;
	input.count = 0; 
	input.capacity = 10; // 10 is a decent place to start with
	input.number = malloc(input.capacity * sizeof(input.number));

	int c;
	int choice = 0;
	WINDOW *menu_win;
	MEVENT event;
	
	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;
	
	initscr(); // Screen initialization
	cbreak(); // Disable line buffering
	noecho(); // Stop passing key input to terminal
	keypad(stdscr, TRUE);

	attron(A_REVERSE);
	mvprintw(23, 1, "Welcome to Visual Algorithms, a TUI to illustrate the process of sorting algorithms.");
	refresh();
	attroff(A_REVERSE);
	
	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	print_menu(menu_win, 1);
	mousemask(ALL_MOUSE_EVENTS, NULL);

	while(1) {
		c = wgetch(menu_win);
		switch(c)
			{
			case KEY_MOUSE:
				if (getmouse(&event) == OK) {
					if (event.bstate & BUTTON1_PRESSED) {
						report_choice(event.x + 1, event.y + 1, &choice);
						if (choice == -1)
							goto end;

						mvprintw(22, 1, "Choice made is: %d", choice, choices[choice - 1]);
						refresh();
					}

					print_menu(menu_win, choice);
					break;
				}
			}
	}
	

 end:
	endwin();
	return 0;
}
