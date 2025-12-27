#include <stdio.h>
#include <stdint.h>
#include <math.h>

int find_lsb_pos(unsigned int x)
{
    unsigned int mask = x & -x;

    int pos = 0;

    while (mask)
    {
        mask >>= 1;
        pos++;
    }

    return pos;
}

int main()
{
    uint32_t x = 0b11010000;

    int lsb_pos = find_lsb_pos(x);

    printf("Vi tri bit 1 thap nhat trong %u la: %d\n", x, lsb_pos);
}