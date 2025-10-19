#include <stdio.h>

int main(void)
{
    register int x = 5;
    printf("% d\n", x);
    printf("% p\n", &x);
    return 0;
}