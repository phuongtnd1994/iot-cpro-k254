#include <stdio.h>

int main()
{
    int n = 5;

    if ((n & 1) == 1)
    {
        printf("%d la so le\n", n);
    }
    else
    {
        printf("%d la so chan\n", n);
    }
}