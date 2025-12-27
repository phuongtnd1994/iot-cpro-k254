#include <stdio.h>
int main()
{
    // Sắp xếp mảng tăng dần.	Dùng bubble sort hoặc selection sort.

    int a[] = {64, 34, 25, 12, 22, 11, 90};
    int sizeOfA = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < sizeOfA - 1; i++)
    {
        for (int j = 0; j < sizeOfA - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                // Hoán đổi a[j] và a[j+1]
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("Mang sau khi sap xep tang dan:\n");
    for (int i = 0; i < sizeOfA; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}