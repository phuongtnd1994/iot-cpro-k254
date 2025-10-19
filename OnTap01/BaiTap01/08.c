#include <stdio.h>
#include <stdint.h>

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
    uint8_t pb2 = (uint8_t)(~x + 1);

    printf("X: %u\n", x);
    print_bits(x);

    printf("Phan bu mod 2: %u\n", pb2);
    print_bits(pb2);
}