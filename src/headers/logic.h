//in-game logic headers
//by Rabbitlancer

#define TIME_THRESHOLD CLOCKS_PER_SEC*0.03

enum t_state { UNDEFINED, WORKING, ERROR, DONE };

static t_state state;

static clock_t t;

int is_complete();
int loop();
int wait();
