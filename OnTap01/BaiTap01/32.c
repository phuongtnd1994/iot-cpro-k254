#include <stdio.h>

typedef struct
{
    char x;
    int y;
} mystruct;

int main(void)
{
    printf("Size of mystruct: %ld\n", sizeof(mystruct));
}