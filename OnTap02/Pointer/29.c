#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M;
    int **a;

    printf("Nhap so dong N: ");
    scanf("%d", &N);
    printf("Nhap so cot M: ");
    scanf("%d", &M);

    a = (int **)malloc(N * sizeof(int *));

    for (int i = 0; i < N; i++)
    {
        a[i] = (int *)malloc(M * sizeof(int));
    }

    // Nhap gia tri cho ma tran
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // In ma tran
    printf("Ma tran vua nhap la:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // free memory
    for (int i = 0; i < N; i++)
    {
        free(a[i]);
    }
    free(a);
}