call C:\Users\k4887\Documents\GitHub\Windows\汇编\调试\set.bat

ml /c /coff B.asm
link /subsystem:windows B.obj
::link /subsystem:console B.obj
::双冒号后面是注释
B
