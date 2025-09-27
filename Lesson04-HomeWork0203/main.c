#include <stdio.h>
#include <signal.h>

static volatile sig_atomic_t g_stop = 0; // lấy từ thư viện signal.h; dùng làm cờ đảm bảo tính atomic
static void on_sigint(int sig)
{
    (void)sig;
    g_stop = 1;
} // hàm xử lý tín hiệu ngắt

int main()
{
    signal(SIGINT, on_sigint);
}