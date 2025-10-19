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

