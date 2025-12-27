#include <stdio.h>
#include <stdlib.h>

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

void fn_increase(int *p)
{
    (*p)++;
}

void fn_reverse_string(char *s)
{
    char *left = s;
    char *right = s;
    char temp;

    while (*right != '\0')
    {
        right++;
    }

    // Bo ky tu \0
    right--;

    while (left < right)
    {
        temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

int *fn_max_element(int *a, int n)
{
    int *maxPtr = a;

    for (int i = 1; i < n; i++)
    {
        if (*(a + i) > *maxPtr)
        {
            maxPtr = a + i;
        }
    }

    return maxPtr;
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

    // fn_q14();

    // 15	In kích thước kiểu dữ liệu thông qua con trỏ void.

    double x15 = 10;
    void *p15 = &x15;

    printf("Kich thuoc kieu double = %zu bytes\n", sizeof(*(double *)p15));

    // 16	Gán con trỏ p trỏ tới mảng a[5], in giá trị bằng p.

    int a16[5] = {10, 20, 30, 40, 50};
    int *p16;

    p16 = a16;

    for (int i = 0; i < 5; i++)
    {
        printf("Gia tri a16[%d] = %d\n", i, *(p16 + i));
    }

    // 17	Dùng con trỏ để đếm số ký tự trong chuỗi.
    char str17[] = "123123123";
    char *p17 = str17;

    int count17 = 0;
    while (*p17 != '\0')
    {
        count17++;
        p17++;
    }
    printf("So ky tu trong chuoi = %d\n", count17);

    // 18	Truyền con trỏ vào hàm để thay đổi giá trị biến gốc.
    int x18 = 5;

    fn_increase(&x18);
    printf("Gia tri x18 sau khi tang len 1 = %d\n", x18);

    // 19	So sánh địa chỉ của hai con trỏ trong cùng mảng.

    int a19[] = {10, 20, 30, 40, 50};

    int *p19_1 = &a19[1];
    int *p19_2 = &a19[3];
    if (p19_1 < p19_2)
    {
        printf("Dia chi p19_1 nho hon dia chi p19_2\n");
    }
    else if (p19_1 > p19_2)
    {
        printf("Dia chi p19_1 lon hon dia chi p19_2\n");
    }
    else
    {
        printf("Dia chi p19_1 bang dia chi p19_2\n");
    }

    // 20	Dùng con trỏ để sao chép chuỗi (không dùng strcpy).
    char str20[] = "123123123";
    char dsst20[20];

    char *p20_src = str20;
    char *p20_dst = dsst20;
    while (*p20_src != '\0')
    {
        *p20_dst++ = *p20_src++;
    }

    *p20_dst = '\0';
    printf("Chuoi sau khi sao chep: %s\n", dsst20);

    // 21	Dùng malloc để cấp phát mảng 10 phần tử int và in chúng.
    int *a21;
    a21 = (int *)malloc(10 * sizeof(int));

    if (a21 == NULL)
    {
        printf("Cap phat bo nho khong thanh cong!\n");
        return 1;
    }

    for (int i = 0; i < 10; i++)
    {
        a21[i] = i * 10;
        printf("a21[%d] = %d\n", i, a21[i]);
    }

    free(a21);

    // 22	Viết hàm trả về con trỏ trỏ tới phần tử lớn nhất trong mảng.

    int a22[] = {10, 50, 30, 70, 20};
    int sizeOfA22 = sizeof(a22) / sizeof(a22[0]);
    int *maxPtr = fn_max_element(a22, sizeOfA22);
    printf("Phan tu lon nhat trong mang la: %d\n", *maxPtr);

    // 23	Dùng con trỏ để đảo ngược chuỗi.

    char str23[] = "Hello 123456!";

    printf("Chuoi truoc khi dao nguoc: %s\n", str23);
    fn_reverse_string(str23);
    printf("Chuoi sau khi dao nguoc: %s\n", str23);
}