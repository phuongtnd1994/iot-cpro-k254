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
    // print_bits(~mask);
    printf(")\n");

    printf("Truoc khi toggle bit %d: ", n);
    print_bits(x);

    x ^= (1u << n);

    printf("Sau khi  toggle bit %d: ", n);
    print_bits(x);
    printf("(%u)\n", x);
    return 0;
}