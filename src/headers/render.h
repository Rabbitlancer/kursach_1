//render subsystem headers
//by Rabbitlancer

#include "types.h"

#define HP_HEIGHT_TITLE 3
#define HP_HEIGHT 4
#define UC 4
#define LC 4

extern t_renderer k_renderer;
extern struct cell *map_objects;
extern unsigned int map_count;
extern struct tank player;

unsigned int step = 0;
int width, height;
char **rfield;

int render_init();
int render_update();
int render_loop();
