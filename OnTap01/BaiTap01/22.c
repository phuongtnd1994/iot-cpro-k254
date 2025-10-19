#include <string.h>
#include <stdlib.h>

int copy(char *scr, char *dst, unsigned int size)
{
    char *s1;
    s1 = malloc(1);

    while (size--)
    {
        *s1++ = *scr++;
        *dst++ = *s1;
    }
    return 0;
}
int main()
{
    char source[] = "Hello, World!";
    char destination[20];

    copy(source, destination, strlen(source) + 1);

    return 0;
}