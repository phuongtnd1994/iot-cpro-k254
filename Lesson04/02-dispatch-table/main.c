#include <stdio.h>
#include "command.h"
#include "command-handlers.h"

static const Command command_table[] = {
    {CMD_MOVE, handle_move},
    {CMD_STOP, handle_stop},
    {CMD_STATUS, handle_status},
};

static const int num_commands = sizeof(command_table) / sizeof(command_table[0]);

void dispatch_command(int command_id, int parameter)
{
    for (int i = 0; i < num_commands; i++)
    {
        if (command_table[i].command_id == command_id)
        {
            command_table[i].handler(parameter);
            return;
        }
    }

    printf(" -> SYSTEM: Unknown command ID: %d\n", command_id);
}

int main()
{
    int cmd_id, param;

    printf("Robot Control CLI - Enter command as 'ID parameter'. (e.g., '1 100')\n");
    printf("Commands: 1=MOVE, 2=STOP, 3=STATUS, 0=QUIT\n");

    while (1)
    {
        printf("> ");
        if (scanf("%d %d", &cmd_id, &param) != 2)
        {
            while (getchar() != '\n')
                ;

            printf("Invalid input format. Please enter two integers.\n");
            continue;
        }

        if (cmd_id == CMD_QUIT)
        {
            break;
        }

        dispatch_command(cmd_id, param);
    }

    printf("Exiting Robot Control CLI.\n");
    return 0;
}
