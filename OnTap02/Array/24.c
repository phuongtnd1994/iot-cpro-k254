#include <stdio.h>

int main()
{
    // Đảo thứ tự từng nhóm 3 phần tử.	Duyệt theo bước 3 và hoán đổi trong nhóm.
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int sizeOfA = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < sizeOfA; i += 3)
    {
        int end = (i + 2 < sizeOfA) ? i + 2 : sizeOfA - 1;
        int start = i;
        while (start < end)
        {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
            start++;
            end--;
        }
    }
    printf("Mang sau khi dao thu tu tung nhom 3 phan tu:\n");
    for (int i = 0; i < sizeOfA; i++)
    {
        printf("%d ", a[i]);
    }
}