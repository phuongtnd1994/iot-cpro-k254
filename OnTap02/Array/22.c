#include <stdio.h>

int main()
{
    // Tìm phần tử xuất hiện nhiều nhất.	Đếm tần suất từng giá trị.

    int a[] = {1, 2, 2, 3, 4, 4, 4, 5};
    int sizeOfA = sizeof(a) / sizeof(a[0]);
    int maxCount = 1;
    int mostFrequent = a[0];
    for (int i = 0; i < sizeOfA; i++)
    {
        int count = 1;
        for (int j = i + 1; j < sizeOfA; j++)
        {
            if (a[j] == a[i])
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            mostFrequent = a[i];
        }
    }

    printf("Phan tu xuat hien nhieu nhat la %d voi tan suat %d lan\n", mostFrequent, maxCount);
}