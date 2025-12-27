#include <stdio.h>

int main()
{
    // Đảo ngược mảng.	Hoán đổi arr[i] và arr[n-1-i].

    int a[] = {10, 20, 30, 40, 50};
    int sizeOfA = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < sizeOfA / 2; i++)
    {
        int temp = a[i];
        a[i] = a[sizeOfA - 1 - i];
        a[sizeOfA - 1 - i] = temp;
    }

    printf("Mang sau khi dao nguoc:\n");
    for (int i = 0; i < sizeOfA; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}