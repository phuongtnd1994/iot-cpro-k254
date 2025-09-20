#include <stdio.h>

void print_invocation_count()
{
    static int invocation_count = 0;

    invocation_count++;

    printf("This function has been called %d time(s). \n", invocation_count);
}

int main()
{
    print_invocation_count();
    print_invocation_count();
    print_invocation_count();
}