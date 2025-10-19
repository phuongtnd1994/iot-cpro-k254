#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void myfunction(char **q)
{
    *q = (char *)malloc(8);
    if (q)
    {
        memcpy(*q, "hello", 6);
    }
}

void main(void)
{
    char *p = NULL;
    myfunction(&p);
    printf("%s\n", p);
}
