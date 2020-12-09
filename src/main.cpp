#include <cstdint>

#include "game.hpp"

int main(int argc, char *argv[])
{
	int init_status = init();

	if (init_status == 0) run();

	close();

	return 0;
}


/*
Player model 1
   <0>
   ¯ |

Player model 2
   _ |
   <0>
*/



/*#define GRASS = '~';

WINDOW *term;
int ended = 0;
int x_ofs = 0;
int y_ofs = 0;
int term_x = 0;
int term_y = 0;

void init_screen()
{
	term = initscr();

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
	
	cbreak();
	noecho();
	nodelay(term, true);

	nonl();
	intrflush(term, false);
	keypad(term, true);

	wrefresh(term);
	
}

int right_size()
{
	getmaxyx(term,term_y,term_x);

	x_ofs = (term_x-80)/2;
	y_ofs = (term_y-25)/2;

	return ((term_x>=80)&&(term_y>=25));
}

void startMenu()
{
	attron(COLOR_PAIR(1));
	mvwprintw(term, 8 + y_ofs, 24 + x_ofs, "-- -= S K I R M I S H =- --");
	mvwprintw(term, 11 + y_ofs, 28 + x_ofs, " by: Justin Pierro");
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(4));
	mvwprintw(term,22+y_ofs,26+x_ofs, "Press any key to start!");
	attroff(COLOR_PAIR(4));
	
	while (wgetch(term) == ERR)
		;
	wclear(term);
}

void  initField()
{
	attron(COLOR_PAIR(3));
	mvwprintw(term, 15, 0, "#########################");
	attroff(COLOR_PAIR(3));
	while (wgetch(term) == ERR)
		;
	wclear(term);
}


int main()
{
	srand(time(NULL));
	init_screen();

	if (!right_size())
	{
		endwin();
		fprintf(stderr, "Skirmish must be run in an 80x25 terminal!\n");
		return -1;
	}

	startMenu();
	initField();
	initKnights();

	while (wgetch(term) != ERR)
		;
	endwin();

	return 0;
} */