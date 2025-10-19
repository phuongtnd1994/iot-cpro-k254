#include <stdio.h>

union U
{
    int val;
    char byte[4];
};

int main(void)
{
    union U u;
    u.val = 0x12345678;
    printf(" %x %x %x %x\n ", u.byte[0], u.byte[1], u.byte[2], u.byte[3]);
}