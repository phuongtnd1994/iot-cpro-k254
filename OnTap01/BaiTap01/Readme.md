# Ôn tập Bai Tap - Ly Thuyet 01

## Bitwise
- 01: Làm thế nào để bật (set) một bit cụ thể trong một biến? 
    - x |= (1u<<n)
    - Tạo mặt nạ or với 1
- 02: Làm thế nào để tắt (set) một bit cụ thể trong một biến?
    - x &= ~(1u << n);
    - Tạo mặt nạ, nhưng chú ý phải có ~ đảo bit để đảo tất cả 1 còn lại đúng bit n là 0
- 03: Làm thế nào để đảo (toggle) một bit cụ thể trong một biến?
    - x ^= (1u << n);
    - Tạo mặt nạ, dùng phép toán XOR (0 ^ 1 = 1, 1 ^ 1 = 0)



