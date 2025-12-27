#include <stdio.h>

int main()
{
    // Nhân hai ma trận 3x3.	arrC[i][j] = Σ arrA[i][k]*arrB[k][j].
    int arrA[3][3];
    int arrB[3][3];
    int arrC[3][3] = {0}; // Khởi tạo ma trận kết quả với 0

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Nhap phan tu arrA[%d][%d]: ", i, j);
            scanf("%d", &arrA[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Nhap phan tu arrB[%d][%d]: ", i, j);
            scanf("%d", &arrB[i][j]);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arrC[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                arrC[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    printf("Ma tran arrC (tich cua arrA va arrB) la:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arrC[i][j]);
        }
        printf("\n");
    }
}