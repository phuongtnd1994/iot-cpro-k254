#include <stdio.h>

void print_bits(unsigned int x)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (x >> i) & 1);
    }
}

void swap_xor(unsigned *a, unsigned *b)
{
    if (a == b)
        return;

    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main()
{
    unsigned x = 23;
    unsigned y = 45;

    printf("Truoc: x=%u, y=%u\n", x, y);
    swap_xor(&x, &y);
    printf("Sau  : x=%u, y=%u\n\n", x, y);
}