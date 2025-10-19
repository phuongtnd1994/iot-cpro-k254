int a = 10;
const int b = 5;
static int c = 3;
int func(void)
{
    int d = 2;
    return a + b + c + d;
}
int main(void)
{
    return func();
}