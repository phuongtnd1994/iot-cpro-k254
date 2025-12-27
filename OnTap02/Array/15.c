#include <stdio.h>

int main()
{
    // Tìm phần tử lớn nhất và vị trí của nó.	Ghi lại chỉ số khi tìm max.
    int a[] = {15, 22, 8, 19, 31, 7};
    int sizeOfA = sizeof(a) / sizeof(a[0]);
    int max = a[0];
    int maxIndex = 0;
    for (int i = 1; i < sizeOfA; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            maxIndex = i;
        }
    }
    printf("Gia tri lon nhat trong mang = %d tai vi tri a[%d]\n", max, maxIndex);
}