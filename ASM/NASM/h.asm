;----------------------Hello World Program--------------------------
; by alongwy
; 编译： nasm -f elf helloworld.asm
; 链接： ld -m elf_i386 helloworld.o -o helloworld
;        64位系统需要 elf_i386 选项
; 运行： ./helloworld
;-------------------------------------------------------------------

SECTION .data                            ; 数据段
    msg     db  'Hello',' World!', 0Ah      ; 创建字符串，0Ah是换行符

SECTION .text                            ; 代码段
global  _start
_start:
    mov     edx, 13     ; 字符串长度
    mov     ecx, msg    ; 字符串地址
    mov     ebx, 1      ; 写入到标准输出
    mov     eax, 4      ; SYS_WRITE 中断操作数 4
    int     80h         ; 调用系统中断

    mov     ebx, 0      ; 返回值
    mov     eax, 1      ; SYS_EXIT 中断操作数 1
    int     80h         ; 调用系统中断