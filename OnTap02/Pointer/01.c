#include <stdio.h>

void function_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    // 11	Khai báo con trỏ trỏ đến biến int và in địa chỉ, giá trị.
    int x = 10;
    int *p = &x;

    printf("%d\n", x);
    printf("%p \n", p);

    // 12	Dùng con trỏ để hoán đổi hai số.
    int a = 5, b = 10;

    printf("Truoc khi swap: a = %d, b = %d\n", a, b);
    function_swap(&a, &b);
    printf("Sau khi swap: a = %d, b = %d\n", a, b);

    // 13	Dùng con trỏ để tính tổng các phần tử mảng.
}