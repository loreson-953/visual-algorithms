#ifndef UI_H
#define UI_H
#include <ncurses.h>

typedef struct {
	int height;
	int width;
	int start_x;
	int start_y;

	char border_vertical;
	char border_horizontal;
	char border_corners;
	
} window_info;

void ncurse_initialization(void);

WINDOW *create_new_window(int height, int width, int start_y, int start_x);
void print_options_window(WINDOW *options_window, int highlight);

#endif
