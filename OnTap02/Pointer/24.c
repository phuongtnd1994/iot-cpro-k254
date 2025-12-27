#include <stdio.h>
#include <stdlib.h>

int **fn_input_matrix(int rows, int cols)
{
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Nhap phan tu matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    return matrix;
}

void fn_print_matrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void fn_free_matrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main()
{
    // 24	Dùng con trỏ để nhập và in ma trận.
    int rows, cols;
    printf("Nhap so dong cua ma tran: ");
    scanf("%d", &rows);
    printf("Nhap so cot cua ma tran: ");
    scanf("%d", &cols);

    int **matrix = fn_input_matrix(rows, cols);

    printf("Ma tran vua nhap la:\n");
    fn_print_matrix(matrix, rows, cols);

    fn_free_matrix(matrix, rows);

    return 0;
}
