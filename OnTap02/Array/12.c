#include <stdio.h>

int main()
{
    // 12	Tìm giá trị lớn nhất trong mảng.	Duyệt mảng và so sánh max.
    int a[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    int max = a[0];
    for (int i = 1; i < 5; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    printf("Gia tri lon nhat trong mang = %d\n", max);
}