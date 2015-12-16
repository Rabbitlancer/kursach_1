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

static void fly(int id) {
	struct shot *info = (struct shot *)map_objects[id].content;
	int newx = map_objects[id].x, newy = map_objects[id].y;

	switch (info->dir) {
		case UP: --newy; break;
		case DOWN: ++newy; break;
		case LEFT: --newx; break;
		case RIGHT: ++newx; break;
	}

	bool colflag = false;
	for (int i = 0; i<map_count; ++i) {
		if (colflag) break;
		if (map_objects[i].type == FENCE
			|| (map_objects[i].type == TANK && !info->friendly)
			|| (map_objects[i].type == ENEMY && info->friendly)) {
			if (map_objects[i].x == newx && map_objects[i].y == newy) {
				colflag = true;
				map_objects[id].type = EMPTY;
				if (map_objects[i].type == FENCE) map_objects[i].type = EMPTY;
				else if (rand_range(10)-(((struct tank *)(map_objects[i].content))->ac))
					--(((struct tank *)(map_objects[i].content))->hp);
			}
		}
	}

	if (map_objects[id].x == newx && map_objects[id].y == newy) map_objects[id].type = EMPTY;

	if (!colflag) {
		map_objects[id].x = newx;
		map_objects[id].y = newy;
		if (newx<0 || newy<0 || newx>=FIELD_WIDTH || newy>=FIELD_HEIGHT) map_objects[id].type = EMPTY;
	}
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
		} else if (map_objects[i].type == PICKUP && id==0) {
			if (map_objects[i].x == newx && map_objects[i].y == newy) {
				map_objects[i].type = EMPTY;
				player.hp++;
			}
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

	int enemies = 4+(int)rand_range(10);
	for (int i = 0; i<enemies; ++i) {
		x = 6+(int)rand_range(FIELD_WIDTH-12);
		y = 6+(int)rand_range(FIELD_HEIGHT-12);
		if (push_object(ENEMY, x, y)<0) return -1;
	}

	int fences = 20+(int)rand_range(80);
	for (int i = 0; i<fences; ++i) {
		x = 1+(int)rand_range(FIELD_WIDTH-2);
		y = 1+(int)rand_range(FIELD_HEIGHT-2);
		if (push_object(FENCE, x, y)<0) return -1;
	}
}

t_dir choose_dir() {
	if (rand_range(100)-75>0) return UP;
	if (rand_range(100)-67>0) return DOWN;
	if (rand_range(100)-50>0) return LEFT;
	return RIGHT;
}

t_dir opposite_dir(t_dir org) {
	if (org == UP) return DOWN;
	if (org == DOWN) return UP;
	if (org == LEFT) return RIGHT;
	if (org == RIGHT) return LEFT;
}

void ai(int id) {
	struct tank *info = (struct tank *)(map_objects[id].content);

	if (info->hp<=0) map_objects[id].type = EMPTY;

	if (info->ai_state == UNKNOWN) {
		info->dir = choose_dir();

		if (rand_range(100)-50>0) info->ai_state = DRIVE;
		else info->ai_state = SHOOT;

	} else if (info->ai_state == DRIVE) {
		if (rand_range(100)-10>0) {
			drive(info->dir, id);
			if (rand_range(100)-70>0) info->dir = choose_dir();
		} else info->ai_state = SHOOT;

	} else if (info->ai_state == SHOOT) {
		push_object(ESHOT, map_objects[id].x, map_objects[id].y, info->dir);
		info->ai_state = RETREAT;

	} else {
		info->dir = opposite_dir(info->dir);
		info->ai_state = DRIVE;
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
	if (generate_map()<0) return 1;

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
		case ' ': push_object(FSHOT, map_objects[0].x, map_objects[0].y, player.dir); break;
		case 'o': exit(0); break;
	}
	pool_update();
	if (player.hp<1) state = DONE;
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
	if (type == ENEMY) {
		struct tank *en = new tank;
		en->hp = 1+(int)rand_range(5);
		en->ac = 1+(int)rand_range(5);
		en->dir = UP;
		en->ai_state = UNKNOWN;
		map_objects[map_count-1].content = (void*)en;
	}

	map_objects[map_count-1].x = x;
	map_objects[map_count-1].y = y;
}

//a special overload for bullets
static int push_object(t_object type, unsigned int x, unsigned int y, t_dir dir) {
	if (map_pool - map_count < 5)
		if (repool() < 0) return -1;

	++map_count;
	map_objects[map_count-1].type = type;
	struct shot *ne = new shot;
	ne->dir = dir;
	ne->friendly = (type == FSHOT);
	map_objects[map_count-1].content = (void*)ne;

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
				ai(i);
			break;
			case FSHOT:
			case ESHOT: tspr = '*'; fly(i); break;
			case FENCE: tspr = 'H'; break;
			case PICKUP: tspr = '$'; break;
			default: tspr = ' '; break;
		}
		map_objects[i].sprite = tspr;
	}
}
