#include <stdio.h>

int main()
{
    // Đếm số chẵn và lẻ trong mảng.	Kiểm tra từng phần tử bằng toán tử %.
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sizeOfA = sizeof(a) / sizeof(a[0]);
    int evenCount = 0;
    int oddCount = 0;

    for (int i = 0; i < sizeOfA; i++)
    {
        if (a[i] % 2 == 0)
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }
    }
    printf("So luong so chan = %d\n", evenCount);
    printf("So luong so le = %d\n", oddCount);
}