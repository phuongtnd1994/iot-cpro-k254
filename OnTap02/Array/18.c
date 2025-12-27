#include <stdio.h>
int main()
{
    // Gộp hai mảng A và B thành C.	Copy từng phần tử của A rồi B vào C.

    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6, 7, 8};
    int sizeOfA = sizeof(a) / sizeof(a[0]);
    int sizeOfB = sizeof(b) / sizeof(b[0]);

    int sizeOfC = sizeOfA + sizeOfB;
    int c[sizeOfC];
    for (int i = 0; i < sizeOfA; i++)
    {
        c[i] = a[i];
    }
    for (int i = 0; i < sizeOfB; i++)
    {
        c[sizeOfA + i] = b[i];
    }
    printf("Mang C sau khi gop A va B:\n");
    for (int i = 0; i < sizeOfC; i++)
    {
        printf("%d ", c[i]);
    }

    printf("\n");
}