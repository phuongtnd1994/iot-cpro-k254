#include <stdio.h>

void main(void)
{
    char array[20];
    for (int i = 0; i < 20; i++)
    {
        array[i] = i;
    }

    int *p = (int *)array;
    p++;
    p++;

    printf("%ld\n", sizeof(int));
    printf("%ld\n", sizeof(char));

    printf("Value at p: 0x%x\n", *p);
    printf("%i", *p);
}