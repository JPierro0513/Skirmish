#include <unistd.h>
#include <ncurses.h>
#include <string>

#include "game.hpp"

struct 
{
    vec2i pos;
    char disp_char;
} player;

WINDOW *term;

int init()
{
    term = initscr();
    cbreak();
    noecho();
    clear();
    refresh();

    keypad(term, true);
    nodelay(term, true);
    curs_set(0);

    if(!has_colors())
    {
        endwin();
        printf("ERROR: Terminal does not support color.\n");
        exit(1);
    }

    start_color();
    attron(A_BOLD);
    box(term, 0, 0);
    attroff(A_BOLD);

    return 0;
}

void run()
{
    player.disp_char = '0';
    player.pos = {10, 5};

    int c;

    bool exit = false;

    while(1)
    {
        c = wgetch(term);

        mvaddch(player.pos.y, player.pos.x, ' ');

        switch (c)
        {
        case 'q':
            exit = true;
            break;
        case 'w':
            player.pos.y--;
            break;
        case 'a':
            player.pos.x--;
            break;
        case 's':
            player.pos.y++;
            break;
        case 'd':
            player.pos.x++;
            break;
        default:
            break;
        }

        mvaddch(player.pos.y, player.pos.x, player.disp_char);

        if (exit) break;

        usleep(10000);
        refresh();
    }
}

void close()
{
    endwin();
}