# Ôn tập Bài tập - Lý Thuyết 01

## Bitwise
- 01: Làm thế nào để bật (set) một bit cụ thể trong một biến? 
    - x |= (1u<<n)
    - Tạo mặt nạ OR với 1

- 02: Làm thế nào để tắt (set) một bit cụ thể trong một biến?
    - x &= ~(1u << n);
    - Tạo mặt nạ, nhưng chú ý phải có ~ đảo bit để đảo tất cả 1 còn lại đúng bit n là 0; sau đó AND

- 03: Làm thế nào để đảo (toggle) một bit cụ thể trong một biến?
    - x ^= (1u << n);
    - Tạo mặt nạ, dùng phép toán XOR (0 ^ 1 = 1, 1 ^ 1 = 0)
- 04: Làm thế nào để kiểm tra một bit cụ thể đã được bật hay chưa?
    - x & (1u << n)
    - Khi tạo mặt nạ, dùng phép toán AND, sẽ chỉ giữ lại bit ở vị trí n, còn lại sẽ = 0

- 05: Làm thế nào để hoán đổi hai số mà không cần biến thứ ba?
    - a ^= b; b ^= a ; a ^= b
    - a0 = a0 ^ b0; 
    - b0 = bo ^ (a0 ^bo) = (b0 ^ bo0) ^ a0= a0; 
    - a0 = (a0 ^ b0) ^ b0 = (a0 ^ b0) ^ a0 = (a0 ^ a0) ^ b0 = b0

- 06: Viết 1 dòng code để kiểm tra n có phải lũy thừa của 2 không.
    - Cac so luy thua 2 se co dang xxxx0
    - Can kiem tra xem duoi co so 1 hay khong la duoc
    
- 06+1: Làm thế nào để đếm số bit 1 trong biểu diễn nhị phân của một số?
    - Dùng buildin: __builtin_popcount

- 07: Làm thế nào để kiểm tra một số là chẵn hay lẻ?
    - Dùng phép toán And với 0..1

- 08: Làm thế nào để tìm bù 2 (2’s complement) của một số nhị phân?
    - x + (-x) mod 2^n = 0
    - -x = (2^n) - x
    - ~x = (2^n -1) - x
    - (~x) + 1 = 2^n - x