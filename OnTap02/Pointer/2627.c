#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    if (b == 0)
    {
        printf("Loi: chia cho 0!\n");
        return 0;
    }
    return a / b;
}

int main()
{
    // Dùng hàm con trỏ để chọn phép tính (+,-,*,/).	Mảng con trỏ hàm, chọn theo input.
    int a, b, choice;

    int (*func[4])(int, int) = {add, sub, mul, divide};

    printf("Nhap hai so nguyen: ");
    scanf("%d %d", &a, &b);

    printf("Chon phep tinh (0: Cong, 1: Tru, 2: Nhan, 3: Chia): ");
    scanf("%d", &choice);

    if (choice < 0 || choice > 3)
    {
        printf("Lua chon khong hop le!\n");
    }
    else
    {
        int result = func[choice](a, b);
        printf("Ket qua: %d\n", result);
    }
}