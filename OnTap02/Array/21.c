#include <stdio.h>

int main()
{
    // Chèn phần tử vào vị trí bất kỳ.	Dịch phần tử sang phải và gán giá trị mới.

    int a[100] = {10, 20, 30, 40, 50};
    int sizeOfA = 5; // Kích thước hiện tại của mảng
    int k, value;
    printf("Nhap vi tri k can chen (0-%d): ", sizeOfA);
    scanf("%d", &k);
    if (k < 0 || k > sizeOfA)
    {
        printf("Vi tri k khong hop le!\n");
        return 1;
    }
    printf("Nhap gia tri can chen: ");
    scanf("%d", &value);

    for (int i = sizeOfA; i > k; i--)
    {
        a[i] = a[i - 1];
    }
    a[k] = value;
    sizeOfA++; // Tăng kích thước mảng sau khi chèn
    printf("Mang sau khi chen phan tu %d tai vi tri %d:\n", value, k);
    for (int i = 0; i < sizeOfA; i++)
    {
        printf("%d ", a[i]);
    }
}