#include <stdio.h>

int main()
{
    // Tính tổng phần tử ở vị trí chẵn.	Cộng arr[i] với i % 2 == 0.

    int a[] = {10, 21, 32, 43, 54, 65, 76};
    int sizeOfA = sizeof(a) / sizeof(a[0]);
    int sum = 0;
    for (int i = 0; i < sizeOfA; i++)
    {
        if (i % 2 == 0)
        {
            sum += a[i];
        }
    }

    printf("Tong cac phan tu o vi tri chan = %d\n", sum);
}