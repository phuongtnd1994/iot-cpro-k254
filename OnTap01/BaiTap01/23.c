#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void func(void)
{
    char *p = malloc(10);
    strcpy(p, "Embedded");

    printf("String: |%s|\n1", p);
}

int main(void)
{
    func();
    return 0;
}