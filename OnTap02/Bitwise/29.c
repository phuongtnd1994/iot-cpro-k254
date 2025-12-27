#include <stdio.h>
#include <stdint.h>
#include <math.h>

void print_bits(unsigned int x)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (x >> i) & 1);
    }
}

int main()
{
    uint8_t x = 0b00011101;

    uint8_t y = (uint8_t)(-x);

    print_bits(x);
    printf("\n");
    print_bits(y);
    printf("\n");

    uint8_t isolate = x & y;

    print_bits(isolate);
}