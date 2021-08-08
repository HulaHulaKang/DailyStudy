;模式定义
.386                    ;告诉编译器——本程序中使用的指令集   ;后面加个p，如.386p，就可以使用特权指令
.model flat,stdcall     ;model语句:
                        ;.model 内存模式 [,语言模式] [,其他模式]
option casemap:none     ;option xxx=xxx

include windows.inc
include user32.inc
includelib user32.lib
include kernel32.inc
includelib kernel32.lib

.data
szCaption   db  'A MessageBox !',0
szText      db  'Hello, world !',0

.code
start:
    push MB_OKCANCEL or MB_ICONQUESTION
    push offset szCaption
    push offset szText
    push NULL
    call MessageBox
    ;MessageBox,NULL,offset szText,offset szCaption,MB_OK
    invoke ExitProcess,NULL
end start