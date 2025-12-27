#include <stdio.h>

int main()
{
    int a[5];
    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
        sum += a[i];
    }

    printf("Tong cac phan tu trong mang = %d\n", sum);
}