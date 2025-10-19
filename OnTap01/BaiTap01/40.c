#include <stdio.h>

union Data
{
    struct
    {
        unsigned int flag : 3;
        unsigned int mode : 5;
        unsigned int value : 8;
    } info;
    unsigned short raw;
};

int main(void)
{
    union Data d;
    d.raw = 0xABCD; // 0b1010101111001101
    printf("flag = %u, mode = %u, value = %u\n", d.info.flag, d.info.mode, d.info.value);
}