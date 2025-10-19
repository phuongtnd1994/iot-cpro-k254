#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void myfunction(char *q)
{
    memcpy(q, "hello", 5);
}

int main(void)
{
    char *p = malloc(5);
    myfunction(p);
    return 0;
}