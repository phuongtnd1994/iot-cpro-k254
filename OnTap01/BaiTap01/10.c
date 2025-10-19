#include <stdio.h>
#include <stdint.h>

int find_msb_pos(unsigned int x)
{
    int pos = -1;
    while (x)
    {
        x >>= 1;
        pos++;
    }

    return pos;
}

int main()
{
    uint32_t x = 0b11010101;

    int msb_pos = find_msb_pos(x);

    if (msb_pos != -1)
    {
        printf("Vi tri bit 1 cao nhat trong %u la: %d\n", x, msb_pos);
    }
    else
    {
        printf("So %u khong co bit 1 nao.\n", x);
    }
}