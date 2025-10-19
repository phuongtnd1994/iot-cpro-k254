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
- 09: Làm thế nào để kiểm tra hai số có bằng nhau hay không mà không dùng toán tử so sánh?
    - xor mà ra bằng 0 thì là bằng nhau

- 10: Làm thế nào để tìm bit có trọng số lớn nhất (Most Significant Bit - MSB)
    - Chạy vòng lặp

- 11: Làm thế nào để tìm bit có trọng số nhỏ nhất (Least Significant Bit - LSB)?
    - x & (-x), vì ~x + 1 ra -x; tức là sẽ đảo tất cả các bit 0 -> 1 + 1 vào ở phía ngoài cùng bên phải đến bit 1 gần nhất

- 12: Làm thế nào để tắt bit 1 ở ngoài cùng bên phải?
    - x * (x-1)

- 13: Làm thế nào để cô lập bit 1 ở ngoài cùng bên phải?
    - x & (-x)
- 14: Làm thế nào để kiểm tra một số có phải là bội số của 8 hay không?
    - đuôi phải là x000 -> 0b111

| STT| Câu hỏi | Trả lời |
|---------|-----|--------|
|15|Đoạn mã sau có vấn đề gì trong đoạn mã sau không? |chưa cấp phát bộ nhớ cho p|
|16|Hàm hoạt động ra sao? Các biến được cấp phát ở đâu? | biến a,b  được cấp phát ở Unintialized Data (.bss), c được cấp phát ở Initialzied Data (.data), trong hàm thì trên stack, trừ h là static có giá trị nên sẽ ở .data, i malloc trên heap |
|17|a và b được cấp phát và lưu trữ ở đâu?|a và b cùng nằm trên stack, b là biến constant nên sẽ ở .rodata|
|18|Đoạn mã sau có vấn đề gì không? Với RAM = 2000 byte?|đoạn mã này sẽ lỗi vì có cấp phát mà không thu hồi bộ nhớ - 8 * 1000 = 8000 > 2000|
|19|Đoạn mã sau có vấn đề gì không? Làm sao để in ra "hello"?|khi chạy sẽ không in được do truyền vào giá trị và gán nên không được, phải truyền con trỏ con trỏ - xem code 19.c|
|20|Các biến sau được lưu ở đâu?|a là .data, d .bss, b .data, c .rodata, g .data, h .rodata, i stack|
|21|Đoạn mã sau có vấn đề gì không?|size char la 1, size int la 4, vậy 02 lần ++ sẽ trỏ đến vị trí sau 18 byte|
|22|Có vấn đề gì với hàm copy sau?|Chưa khởi tạo cho con trỏ s1|
|23|Đoạn mã sau có vấn đề gì không?|không free bộ nhớ sau khi cấp phát|
|24|Đoạn mã sau có hợp lệ không?|Tạo con trỏ trỏ vào phần chỉ đọc mà sau đó lại thay đổi|
|25|Các biến a, b, c, d được lưu ở đâu trong bộ nhớ?|a .data, b .rodata, c .rodata, d stack|
|26|Đoạn mã sau có vấn đề gì?|Đệ quy không giới hạn vì không thấy điều kiện dừng lại ở đâu|
|27|Đoạn mã sau có in ra đúng giá trị ban đầu không? Tại sao?|con trỏ int 4 byte, char 1 byte, thì bị đổi mất đuôi 1 byte|
|28|Đoạn mã sau có vấn đề gì?|str này trong hàm, là vùng nhớ cục bộ, nên là khi ra khỏi hàm thì sẽ bị xoá đi, và chương trình sẽ lỗi|
|29|1. Kết quả in ra là gì?\n 2. Nếu bỏ từ khóa static, kết quả có khác không?\n 3. Biến count được lưu ở vùng nhớ nào?|in ra 1 2 3\n bỏ static khác vì biến count lúc này sẽ khởi tạo lại mỗi lần gọi trên stack \n biến count lưu ở .bss |
|30|1. Code này có biên dịch được không?\n 2. Nếu không, compiler báo lỗi gì? Tại sao?|register gợi ý trình biên dịch nên để biến x ở thanh ghi của CPU, nên không cho dùng &|
|31|sizeof(struct ab) và sizeof(struct ba) là bao nhiêu?| ab là 8 byte vì a 4 byte + b 1 byte + padding 3 byte là 8 byte, ba không có padding nên là 5 byte|
|32|sizeof(mystruct) sẽ in ra gì?|In ra 8 byte: 4 byte + 1 byte + 3 byte padding|
|33|sizeof(struct A) là bao nhiêu trên hệ thống 32-bit?| 32 bit = 4 bytes - căn theo 4 ; char 1 byte + 3 byte, int 4 byte , short 2 byte + 2 => 12 bytes |
|34|Ảnh hưởng của #pragma pack(1) là gì? Kết quả sizeof(struct B) là bao nhiêu trên hệ thống 32-bit?|đặt lại mức package là 1 bytes, lúc này size là 7 bytes|
|35|Tính sizeof(struct Outer) trên hệ thống 32-bit.| Inner: 1 byte char + 3 padding + 4 byte int =8; int 4 bytes + 8 bytes Innter + 3 byte char + 1 = 16 bytes|
|36|Trong đoạn mã sau, ab.b có giá trị là bao nhiêu?|char có 2 byte, union thì các thuộc tính dùng chung địa chỉ bộ nhớ, nên sẽ là 0xC4|
|37|sizeof(struct Test) là bao nhiêu trên hệ thống 32-bit?|Data = 4 bytes, Test = 1 byte + 3 pads + 4 bytes = 8bytes|
|38|Kết quả khác nhau như thế nào giữa little-endian và big-endian?|litte-end thì 78 56 34 12, big-end thì ngược lại|
|39|sizeof(struct Flags) là bao nhiêu?|ở đây dùng bit fiels, ép + vào = 8 bits < 4 bytes của unsigned int nên kết quả là 4|
|40|"1. Giá trị flag, mode, value sẽ in ra bao nhiêu (giả sử hệ thống little-endian)?\n 2. Tại sao giá trị thay đổi khi chạy trên big-endian?\n 3. Giải thích cách compiler ánh xạ bit field vào raw.|1/ tinh tu 0b1010101111001101 thi flag 5 mode 25, value 171\n 2/ boi vi do la MSB -> lấy ngược từ trái sang \n 3/ lần lượt là 101 11001 10101011|
|41|1. sizeof(struct Packet) là bao nhiêu trên 32-bit?\n 2. Giải thích tại sao sizeof không phải luôn bằng 2?\n 3. Nếu ta gán data.raw = 0xAB, giá trị của id, type, err lần lượt là gì?|1. bits -> bitfield là 4 bytes, header 1 byte + 3 paddings = 8 bytes \n 2. Do là union \n 3.\ 0b10101011 id 1011 = 11, type 010 = 2, err = 1 |
|42|1. sizeof(union Config) là bao nhiêu?\n 2. Tại sao cả hai struct đều có cùng vùng nhớ?\n 3. Nếu gán security.key = 0x7F, giá trị normal.mode có thay đổi không?| 1. 4 bytes do 02 struct cùng dùng bit fields \n 2. Bởi vì đây là 02 mode chạy của config \n 3. 0x7F là 11111111 , giá trị normal mode có đổi vì đây là union cùng chia sẻ bộ nhớ|
|43|1. In ra kết quả gì (với little-endian)?\n 2. Giải thích tại sao việc truy cập ctrl.bits và ctrl.reg lại ảnh hưởng trực tiếp nhau?\n 3. Nếu muốn MODE chiếm bit 4–5 thay vì 1–2, sửa khai báo thế nào?|1. 0b10110010 EN 0 MODE 01 =1 RSV = 0 CLK = 1011 = 11 /n 2. vì là union sẽ chia sẻ bộ nhớ \n 3. Đổi thành CLK 4 bits lên đầu, rồi tiếp là RSV 2 bits là được |
|44|1. sizeof(union Frame) là bao nhiêu?\n 2. Nếu bytes.low = 0xAA và bytes.high = 0xBB, giá trị của info.len, info.type, info.crc là gì?\n 3. Giải thích tại sao giá trị có thể khác nhau giữa compiler (GCC vs ARMCC)?|1. 2 bytes vif 10 + 3 + 3 đúng bằng 16 bits\n 2. 0xAA = 0b10101010  0xBB = 0b10111011 ->  1011101110101010 -> len = 1110101010 = 938, type = 110 = 6 \n 3.|