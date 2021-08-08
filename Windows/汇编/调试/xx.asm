.386
.model flat,stdcall

include <msvcrt.inc>
includelib <msvcrt.lib>

.data
szFormat db "Hello,world!\r\n%d",0
kkkkk DWORD 666

.code
start:
invoke crt_printf,addr szFormat,kkkkk
ret
end start
