import re

input_file = "objdump_output.txt"   # objdump 출력 저장한 파일
output_file = "shellcode.txt"

shellcode_bytes = []

with open(input_file, 'r') as f:
    for line in f:
        match = re.match(r'\s*[0-9a-f]+:\s+((?:[0-9a-f]{2}\s+)+)', line)
        if match:
            bytes_str = match.group(1)
            bytes_split = bytes_str.strip().split()
            shellcode_bytes.extend(bytes_split)

# \x형태로 변환
shellcode = ''.join(f'\\x{b}' for b in shellcode_bytes)

# 출력 저장
with open(output_file, 'w') as f:
    f.write(shellcode)
