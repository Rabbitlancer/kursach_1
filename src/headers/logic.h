//in-game logic headers
//by Rabbitlancer

#include "types.h"

#define TIME_THRESHOLD CLOCKS_PER_SEC*0.05
#define POOL_POWER 100

enum t_state { WEIRD, WORKING, ERROR, DONE };

static t_state state;

static clock_t t;
int **field;

struct cell *map_objects;
unsigned int map_count;
static unsigned int map_pool;

struct tank player;

int init();
int is_complete();
int loop();
int wait();

static double rand_range(double max);
static int repool();
static int push_object(t_object type, unsigned int x, unsigned int y);
static void pool_update();

extern int render_init();
extern int render_update();
extern int render_loop();
