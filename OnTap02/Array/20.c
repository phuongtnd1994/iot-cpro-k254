#include <stdio.h>
int main()
{
    // Xóa phần tử tại vị trí k.	Dịch các phần tử sau k sang trái.

    int a[] = {10, 20, 30, 40, 50};
    int sizeOfA = sizeof(a) / sizeof(a[0]);
    int k;

    printf("Nhap vi tri k can xoa (0-%d): ", sizeOfA - 1);
    scanf("%d", &k);
    if (k < 0 || k >= sizeOfA)
    {
        printf("Vi tri k khong hop le!\n");
        return 1;
    }

    for (int i = k; i < sizeOfA - 1; i++)
    {
        a[i] = a[i + 1];
    }

    sizeOfA--; // Giảm kích thước mảng sau khi xóa
    printf("Mang sau khi xoa phan tu tai vi tri %d:\n", k);
    for (int i = 0; i < sizeOfA; i++)
    {
        printf("%d ", a[i]);
    }
}