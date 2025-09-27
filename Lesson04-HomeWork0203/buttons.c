#include "buttons.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h> // STDIN_FILENO, thư viện POSIX (UNIX standard), cung cấp lời gọi hệ thống và tiện ích ở mức thấp
#include <fcntl.h>  // Lay ra F_GETFL, header POSIX cung cấp hàm và cờ điều khiển file
#include <string.h> // memset

static struct termios orig_termios;

// hàm này đặt terminal về chế độ non-canonical - đọc phím tức thời
static void set_conio_terminal_mode(void)
{
    struct termios new_termios;
    tcgetattr(STDIN_FILENO, &orig_termios); // Lấy cấu hình stdin hiện tại lưu lại
    new_termios = orig_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);          // tắt chế độ canonical và echo
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);   // Set lai cau hinh cua stdin
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);      // Lấy cờ file hiện tại
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK); // Set cờ file không chặn
}

void buttons_init(void)
{
    set_conio_terminal_mode();
    printf("Controls: [m]=toggle AUTO/MANUAL, [w]=manual water, [s]=status, [q]=quit\n");
}

void buttons_shutdown(void)
{
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
}

void buttons_poll(ButtonEvents *ev)
{
    memset(ev, 0, sizeof(*ev));
    int ch;
    while ((ch = getchar() != EOF))
    {
        switch (ch)
        {
        case 'm':
        case 'M':
            ev->toggle_auto_manual = true;
            break;
        case 'w':
        case 'W':
            ev->manual_water = true;
            break;
        case 's':
        case 'S':
            ev->print_status = true;
            break;
        case 'q':
        case 'Q':
            ev->quit = true;
            break;
        }
    }
}