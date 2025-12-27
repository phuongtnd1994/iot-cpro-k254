#include <stdio.h>

int main()
{
    // Loại bỏ phần tử trùng lặp.	So sánh và tạo mảng mới không trùng.

    int a[] = {1, 2, 2, 3, 4, 4, 5, 9};

    int sizeOfA = sizeof(a) / sizeof(a[0]);
    int temp[sizeOfA];
    int newSize = 0;

    for (int i = 0; i < sizeOfA; i++)
    {
        int isDuplicate = 0;
        for (int j = 0; j < newSize; j++)
        {
            if (a[i] == temp[j])
            {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate)
        {
            temp[newSize] = a[i];
            newSize++;
        }
    }

    printf("Mang sau khi loai bo phan tu trung lap:\n");
    for (int i = 0; i < newSize; i++)
    {
        printf("%d ", temp[i]);
    }
}