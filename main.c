#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "algorithms.h"

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

#define WIDTH 30
#define HEIGHT 10

int startx = 0;
int starty = 0;

char *choices[] =
	{
		"1. Bubble Sort",
		"0. Exit"
	};

int n_choices = sizeof(choices) / sizeof(char *);

void print_menu(WINDOW *menu_win, int highlight);
void report_choice(int mouse_x, int mouse_y, int *p_choice);

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

						mvprintw(22, 1, "Choice made is: %d
						
						mvprintw(22, 1, "Choice 
					}
				}
			}
	}
	

 end:
	endwin();
	return 0;
}

void print_menu(WINDOW *menu_win, int highlight) {
	int x = 2;
	int y = 2;

	box(menu_win, 0, 0);

	for (int i = 0; i < n_choices; i++) {
		if (highlight == i + 1) {
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		} else {
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			y++;
		}
	}
	wrefresh(menu_win);
	
}

void report_choice(int mouse_x, int mouse_y, int *p_choice) {
	int i = startx + 2;
	int j = starty + 3;

	for (int choice = 0; choice < n_choices; choice++)
		if (mouse_y == j + choice
			&& mouse_x >= i
			&& mouse_x <= i + strlen(choices[choice]))
			{
				if (choice == n_choices - 1)
					*p_choice = -1;
				else
					*p_choice = choice + 1;
				break;
			}
	
}
