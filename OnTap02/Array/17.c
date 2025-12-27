#include <stdio.h>

int main()
{
    // Tính trung bình cộng các phần tử.	Tổng chia cho số phần tử.

    int a[] = {10, 20, 30, 40, 50};
    int sizeOfA = sizeof(a) / sizeof(a[0]);

    int sum = 0;
    for (int i = 0; i < sizeOfA; i++)
    {
        sum += a[i];
    }
    double average = (double)sum / sizeOfA;
    printf("Trung binh cong cua cac phan tu trong mang = %.2f\n", average);
}