#include <stdio.h>

int main()
{
    // Kiểm tra ma trận đối xứng.	So sánh arr[i][j] và arr[j][i].

    int n;
    printf("Nhap kich thuoc ma tran vuong n x n: ");
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Nhap phan tu arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    int isSymmetric = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != arr[j][i])
            {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric)
        {
            break;
        }
    }

    if (isSymmetric)
    {
        printf("Ma tran la ma tran doi xung.\n");
    }
    else
    {
        printf("Ma tran khong phai la ma tran doi xung.\n");
    }
}