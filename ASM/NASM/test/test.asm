SECTION .data
    text1 db    'Hell','o ,world!',0Ah

SECTION .text
global _start
_start:
    mov edx,14
    mov ecx,text1
    mov     ebx,1
    mov         eax,4
    int 80h


    mov ebx, 0
    mov    eax,       1
    int 80h