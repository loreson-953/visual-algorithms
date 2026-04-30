#include "ui.h"
#include <ncurses.h>
#include <string.h>

const char *choices[] =
	{
		"1. Bubble Sort",
		"0. Exit",
	};

int n_choices = sizeof(choices) / sizeof(char *);

void print_menu(WINDOW *menu_win, int highlight) {
	int x = 2;
	int y = 2;

	box(menu_win, 0, 0);

	for (int i = 0; i < n_choices; ++i) {
		if (highlight == i + 1) {
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		} else mvwprintw(menu_win, y, x, "%s", choices[i]);
		y++;

	}
	wrefresh(menu_win);
	
}

void report_choice(int mouse_x, int mouse_y, int *p_choice) {
	int i = startx + 2;
	int j = starty + 3;

	for (int choice = 0; choice < n_choices; ++choice)
		if (mouse_y == j + choice
			&& mouse_x >= i
			&& mouse_x <= i + strlen(choices[choice]))
			{
				if (choice == n_choices - 1) *p_choice = -1;
				else *p_choice = choice + 1;
				break;
			}
	
}

