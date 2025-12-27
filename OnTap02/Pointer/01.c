#include <stdio.h>

void fn_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void fn_sum_array(int *arr, int size, int *sum)
{
    *sum = 0;
    for (int i = 0; i < size; i++)
    {
        *sum += *(arr + i);
    }
}

void fn_input_array(int *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", ptr + i);
    }
}

void fn_print_array(int *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Phan tu thu %d: %d\n", i, *(ptr + i));
    }
}

void fn_q14()
{
    int a[100];
    int n;

    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);
    fn_input_array(a, n);
    fn_print_array(a, n);
}

int main()
{
    // 11	Khai báo con trỏ trỏ đến biến int và in địa chỉ, giá trị.
    int x = 10;
    int *p = &x;

    printf("%d\n", x);
    printf("%p \n", p);

    // 12	Dùng con trỏ để hoán đổi hai số.
    int a = 5, b = 10;

    printf("Truoc khi swap: a = %d, b = %d\n", a, b);
    fn_swap(&a, &b);
    printf("Sau khi swap: a = %d, b = %d\n", a, b);

    // 13	Dùng con trỏ để tính tổng các phần tử mảng.
    int a13[] = {1, 2, 3, 4, 5};
    int sizeOfA13 = sizeof(a13) / sizeof(a13[0]);

    int sum = 0;
    fn_sum_array(a13, sizeOfA13, &sum);

    printf("Tong cac phan tu trong mang = %d\n", sum);

    // 14	Tạo hàm nhập và in mảng bằng con trỏ.

    fn_q14();
}