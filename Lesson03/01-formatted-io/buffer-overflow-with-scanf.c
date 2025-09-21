#include <stdio.h>

int main()
{
    char name[10];
    printf("Enter your name: ");
    // This is unsafe and can cause buffer overflow
    scanf("%9s", name);
    printf("Hello, %s!\n", name);
    return 0;
}