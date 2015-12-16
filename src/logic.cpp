//in-game logic
//by Rabbitlancer
#include <ctime>
#include <cstdlib>
#include <climits>
#include <curses.h>
#include <openssl/rand.h>
#include "headers/logic.h"

//truly random, truly cryptographically safe, as provided by OpenSSL
//returns an integer from [0; max)
static double rand_range(double max) {
	unsigned int buf;
	RAND_bytes((unsigned char *)&buf, sizeof(unsigned int));
	double frac = (double)buf/(double)UINT_MAX;
	double res = frac*max;
	return res;
}

static void drive(t_dir dir, int id) {
	int newx = map_objects[id].x, newy = map_objects[id].y;

	switch (dir) {
		case UP: --newy; break;
		case DOWN: ++newy; break;
		case LEFT: --newx; break;
		case RIGHT: ++newx; break;
	}

	bool colflag = false;
	for (int i = 0; i<map_count; ++i) {
		if (colflag) break;
		if (map_objects[i].type == WALL || map_objects[i].type == FENCE) {
			if (map_objects[i].x == newx && map_objects[i].y == newy) colflag = true;
		}
	}

	if (!colflag) {
		map_objects[id].x = newx;
		map_objects[id].y = newy;
	}

	((struct tank *)(map_objects[id].content))->dir = dir;
}

int generate_map() {
	push_object(TANK, 2+(int)rand_range(6), 2);

	for (int i = 0; i<FIELD_WIDTH; ++i) {
		if (push_object(WALL, i, 0)<0) return -1;
		if (push_object(WALL, i, FIELD_HEIGHT-1)<0) return -1;
	}
	for (int i = 1; i<FIELD_HEIGHT-1; ++i) {
		if (push_object(WALL, 0, i)<0) return -1;
		if (push_object(WALL, FIELD_WIDTH-1, i)<0) return -1;
	}

	int castles = 1+(int)rand_range(4);
	int x, y;
	for (int i = 0; i<castles; ++i) {
		x = 6+(int)rand_range(FIELD_WIDTH-24);
		y = 3+(int)rand_range(FIELD_HEIGHT-14);
		for (int j = 0; j<8; ++j) {
			if (push_object(WALL, x, y+j)<0) return -1;
			if (push_object(WALL, x+8, y+j)<0) return -1;
		}
		for (int j = 1; j<7; ++j) {
			if (rand_range(100)-25 > 0)
				if (push_object(WALL, x+j, y)<0) return -1;
			if (rand_range(100)-12 > 0)
				if (push_object(WALL, x+j, y+8)<0) return -1;
		}
		if (push_object(PICKUP, x+2+(int)rand_range(4), y+2+(int)rand_range(4))<0) return -1;
	}
}

int init() {
	state = WORKING;

	//init some pool variables
	map_count = 0;
	map_pool = POOL_POWER;

	//init player tank
	player.hp = 3;
	player.ac = 1;

	//start pool
	if (repool() < 0) return 1;
	//start renderer
	if (render_init()) return 1;

	//generate a random map
	generate_map();

	//ncurses init
	initscr();
	raw();
	noecho();
	nodelay(stdscr, true);
	keypad(stdscr, true);

	return 0;
}

int is_complete() {
	if (state == WORKING) return 1;
	else return 0;
}

int loop() {
	t = clock();

	render_update();
	render_loop();
}

int wait() {
	char inp;
	inp = getch();
	flushinp();
	switch (inp) {
		case 'w': drive(UP, 0); break;
		case 's': drive(DOWN, 0); break;
		case 'd': drive(RIGHT, 0); break;
		case 'a': drive(LEFT, 0); break;
		case 'o': exit(0); break;
	}
	pool_update();
	while (clock() - t < TIME_THRESHOLD) {
		; //waiting...
	}
}

//expand the pool
static int repool() {
	map_pool += POOL_POWER;
	map_objects = (struct cell *)realloc(map_objects, sizeof(struct cell)*map_pool);
	if (map_objects == NULL) return -1;
	else return map_pool;
}

//add an object into the pool
static int push_object(t_object type, unsigned int x, unsigned int y) {
	if (map_pool - map_count < 5)
		if (repool() < 0) return -1;

	++map_count;
	map_objects[map_count-1].type = type;
	if (type == TANK) map_objects[map_count-1].content = (void*)&player;
	map_objects[map_count-1].x = x;
	map_objects[map_count-1].y = y;
}

//update pool state
static void pool_update() {
	char tspr = ' ';
	for (int i = 0; i<map_count; ++i) {
		switch (map_objects[i].type) {
			case WALL: tspr = 'X'; break;
			case TANK:
				switch (((struct tank *)(map_objects[i].content))->dir) {
					case UP: tspr = '^'; break;
					case DOWN: tspr = 'V'; break;
					case LEFT: tspr = '<'; break;
					case RIGHT: tspr = '>'; break;
				}
			break;
			case ENEMY:
				switch (((struct tank *)(map_objects[i].content))->dir) {
					case UP: tspr = 'A'; break;
					case DOWN: tspr = 'U'; break;
					case LEFT: tspr = 'C'; break;
					case RIGHT: tspr = 'D'; break;
				}
			break;
			case FSHOT:
			case ESHOT: tspr = '*'; break;
			case FENCE: tspr = 'H'; break;
			case PICKUP: tspr = '$'; break;
			default: tspr = ' '; break;
		}
		map_objects[i].sprite = tspr;
	}
}
