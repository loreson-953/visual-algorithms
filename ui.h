#ifndef UI_H
#define UI_H
#include <ncurses.h>
#include <string.h>

#define WIDTH
#define HEIGHT

int startx;
int starty;

void print_menu(WINDOW *menu_win, int highlight);
void report_choice(int mouse_x, int mouse_y, int *p_choice);

#endif
