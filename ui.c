#include "ui.h"
#include <ncurses.h>

void ncurse_init(void) {
	initscr();
	raw();
	noecho();
}
