#include <stdio.h>

int main()
{
    // Nhập ma trận 3x3, tính tổng đường chéo chính.	Cộng các phần tử arr[i][i].
    int matrix[3][3];
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Nhap phan tu matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        sum += matrix[i][i];
    }
    printf("Tong duong cheo chinh = %d\n", sum);
}