#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fn_swap_all(void *a, void *b, size_t size)
{
    void *temp = malloc(size);
    if (temp == NULL)
    {
        printf("Loi cap phat bo nho!\n");
        return;
    }

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
}

int main()
{
    // 30	Dùng con trỏ void để viết hàm swap tổng quát cho mọi kiểu.	Dùng memcpy trong hàm swap(void*,void*,size_t).

    int x = 10, y = 20;
    float m = 1.5f, n = 2.5f;

    printf("Truoc khi swap: x = %d, y = %d\n", x, y);
    fn_swap_all(&x, &y, sizeof(int));
    printf("Sau khi swap: x = %d, y = %d\n", x, y);

    printf("Truoc khi swap: m = %.2f, n = %.2f\n", m, n);
    fn_swap_all(&m, &n, sizeof(float));
    printf("Sau khi swap: m = %.2f, n = %.2f\n", m, n);
}