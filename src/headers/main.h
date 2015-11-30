//kursach_1 - entry point headers
//by Rabbitlancer

enum t_renderer { UNDEFINED, CONSOLE, IRR_SW, IRR_GL };

t_renderer k_renderer = UNDEFINED;

extern int is_complete();
extern int loop();
extern int wait();

