#include <stdio.h>

char *getString(void)
{
    char str[] = "hello";
    return str;
}
int main(void)
{
    char *s = getString();
    printf("%s\n", s);
}