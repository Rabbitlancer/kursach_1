//types
//by Rabbitlancer

#ifndef __TYPES_H__
#define __TYPES_H__

#define FIELD_WIDTH 60
#define FIELD_HEIGHT 20

enum t_renderer { UNDEFINED, CONSOLE, IRR_SW, IRR_GL };
enum t_object { EMPTY, TANK, ENEMY, WALL, PICKUP, FSHOT, ESHOT, FENCE };
enum t_dir { RIGHT, UP, LEFT, DOWN };
enum t_stat { UNKNOWN, DRIVE, SHOOT, RETREAT };

struct cell {
	t_object type;
	char sprite;
	unsigned int x;
	unsigned int y;
	void *content;
};

struct tank {
	t_dir dir;
	int hp;
	int ac;
	t_stat ai_state;
};

struct shot {
	bool friendly;
	t_dir dir;
};

#endif
