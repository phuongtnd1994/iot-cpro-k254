#ifndef BUTTONS_H
#define BUTTONS_H

#include <stdbool.h>

typedef struct
{
    bool toggle_auto_manual;
    bool manual_water;
    bool print_status;
    bool quit;
} ButtonEvents;

void buttons_init(void);
void buttons_poll(ButtonEvents *ev);
void buttons_shutdown(void);

#endif