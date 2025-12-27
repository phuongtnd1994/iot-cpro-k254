#include <stdio.h>

int main()
{
    // Tính tổng đường chéo phụ ma trận 3x3.	Cộng arr[i][n-1-i].

    int arr[3][3];
    int n = 3;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Nhap phan tu arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        sum += arr[i][n - 1 - i];
    }

    printf("Tong duong cheo phu = %d\n", sum);
}