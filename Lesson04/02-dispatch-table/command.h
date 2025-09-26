#ifndef COMMAND_H
#define COMMAND_H
#include <stdint.h>

typedef enum
{
    CMD_QUIT = 0,
    CMD_MOVE,
    CMD_STOP,
    CMD_STATUS,
} CommandId;

typedef void (*CommandHandler)(int parameter);

typedef struct
{
    int command_id;
    CommandHandler handler;
} Command;

void dispatch_command(int command_id, int parameter);

#endif