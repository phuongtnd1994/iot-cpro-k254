#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 25	Dùng con trỏ để cộng hai ma trận.	Duyệt và tính *(C+i)=*(A+i)+*(B+i).

    int rows = 2, cols = 3;

    int size = rows * cols;

    int *A = (int *)malloc(size * sizeof(int));
    int *B = (int *)malloc(size * sizeof(int));
    int *C = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        A[i] = i + 1;
        B[i] = (i + 1) * 10;
    }

    // Cong nhu mang 01 chieu
    for (int i = 0; i < size; i++)
    {
        *(C + i) = *(A + i) + *(B + i);
    }

    printf("Ma tran C:\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", *(C + i * cols + j));
        }
        printf("\n");
    }

    free(A);
    free(B);
    free(C);
}