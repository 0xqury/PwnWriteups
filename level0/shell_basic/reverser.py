def split_and_reverse(s):
    s_bytes = s.encode() + b'\x00'  # NULL 종료
    padding = (8 - len(s_bytes) % 8) % 8
    s_bytes += b'\x00' * padding  # 8바이트 정렬

    chunks = [s_bytes[i:i+8] for i in range(0, len(s_bytes), 8)]
    for chunk in chunks[::-1]:  # 역순
        hexval = int.from_bytes(chunk, byteorder='little')
        print(f"mov rax, 0x{hexval:016x}")
        print("push rax")

path = "/home/shell_basic/flag_name_is_loooooong"
split_and_reverse(path)
