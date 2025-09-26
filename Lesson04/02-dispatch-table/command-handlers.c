#include "command-handlers.h"
#include <stdio.h>

void handle_move(int parameter)
{
    printf(" %d", parameter);
}

void handle_stop(int parameter)
{
    (void)parameter;
    printf(" -> ROBOT: STOPPED.\n");
}

void handle_status(int parameter)
{
    (void)parameter;
    printf("  -> ROBOT: Status OK. Battery at 95%%.\n");
}