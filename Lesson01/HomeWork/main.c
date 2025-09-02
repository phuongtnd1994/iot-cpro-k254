#include <stdio.h>

void allocate_without_recall()
{
    char *ptr = (char *)malloc(sizeof(char) * 20);
}

void infinite_recursion()
{
    static count = 0;
    printf("count = %d\n", count++);
    infinite_recursion();
}

void main()
{
    printf("hello devlinux\n");
    allocate_without_recall();
    // infinite_recursion();
}