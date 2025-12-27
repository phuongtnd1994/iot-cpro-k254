#include <stdio.h>

void print_bits(unsigned int x)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (x >> i) & 1);
    }
}

int main()
{
    unsigned int x = 0b00011101;
    int n = 3;
    unsigned int mask = (1u << n);

    // In mask ra de nhin
    printf("1u << %d = %u (0b", n, mask);
    print_bits(mask);
    printf(")\n");

    if (x & (1u << n))
    {
        printf("Bit %d dang duoc BAT\n", n);
    }
    else
    {
        printf("Bit %d dang TAT\n", n);
    }
}