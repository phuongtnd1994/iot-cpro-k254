#include <stdlib.h>
#include <string.h>

void myfunction()
{
    char *q;
    for (int i = 0; i < 1000; i++)
    {
        q = (char *)malloc(8);
        if (q != NULL)
        {
            memcpy(q, "hello", 6);
        }
    }
}
int main(void)
{
    myfunction();
    return 0;
}