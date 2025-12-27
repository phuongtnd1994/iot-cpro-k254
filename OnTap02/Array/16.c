#include <stdio.h>

int main()
{
    //   Kiểm tra giá trị x có trong mảng không.	Duyệt tuần tự so sánh từng phần tử.

    int a[] = {10, 20, 30, 40, 50};
    int sizeOfA = sizeof(a) / sizeof(a[0]);
    int x;
    printf("Nhap gia tri x can kiem tra: ");
    scanf("%d", &x);

    int found = 0;
    for (int i = 0; i < sizeOfA; i++)
    {
        if (a[i] == x)
        {
            found = 1;
            break;
        }
    }

    if (found)
    {
        printf("Gia tri %d co trong mang.\n", x);
    }
    else
    {
        printf("Gia tri %d khong co trong mang.\n", x);
    }
}