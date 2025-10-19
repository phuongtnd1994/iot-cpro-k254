#include <stdlib.h>

int a;
char *b;
const char c[20] = " I am a string ";

void func(char d, int c_param, char *f)
{
    int g = 0;
    static int h = 2;
    char *i = NULL;
    i = (char *)malloc(20);
    if (i != NULL)
    {
        free(i);
    }
}

int main()
{
    func('A', 10, " Test string ");
    return 0;
}