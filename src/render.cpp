//render subsystem
//by Rabbitlancer

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <curses.h>
#include "headers/render.h"

using namespace std;

int render_init() {
	step = 0;
	if (k_renderer == CONSOLE) {
		rfield = (char **)calloc(FIELD_HEIGHT, sizeof(char *));
		for (int i = 0; i<FIELD_HEIGHT; ++i) {
			rfield[i] = (char *)calloc(FIELD_WIDTH, sizeof(char));
		}
	}
	return 0;
}

int render_update() {
	++step;
	if (step>2) step = 0;
	if (k_renderer == CONSOLE) {
		for (int i = 0; i<FIELD_HEIGHT; ++i)
			for (int j = 0; j<FIELD_WIDTH; ++j)
				rfield[i][j] = ' ';
		for (int i = 0; i<map_count; ++i) {
			rfield[map_objects[i].y][map_objects[i].x] = map_objects[i].sprite;
		}
	}
	return 0;
}

int render_loop() {
	if (k_renderer == CONSOLE) {
		getmaxyx(stdscr, width, height);

		move(0, 0);
		/*for (int i = 0; i<height; ++i) {
			for (int j = 0; i<width; ++j)
				addch(' ');
			move(i+1, 0);
		}*/

		switch (step) {
			case 0: mvaddch(0,0,'-'); break;
			case 1: mvaddch(0,0,'/'); break;
			case 2: mvaddch(0,0,'\\'); break;
		}

		for (int i = 0; i<FIELD_HEIGHT; ++i) {
			//console_drawline(i);
			for (int j = 0; j<FIELD_WIDTH; ++j) {
				mvaddch(i+UC, j+LC, rfield[i][j]);
			}
		}

		mvprintw(UC+HP_HEIGHT_TITLE, LC+FIELD_WIDTH+LC, "HP:");
		move(UC+HP_HEIGHT, LC+FIELD_WIDTH+LC);
		addch('[');
		for (int i = 0; i<10; ++i) {
			if (i<player.hp) addch('-');
			else addch(' ');
		}
		addch(']');

		refresh();
	}
	return 0;
}
