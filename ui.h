#ifndef UI_H
#define UI_H
#include <ncurses.h>
#include <string.h>

#define WIDTH 30
#define HEIGHT 10

extern int startx;
extern int starty;

extern const char *choices[];

void print_menu(WINDOW *menu_win, int highlight);
void report_choice(int mouse_x, int mouse_y, int *p_choice);

#endif
