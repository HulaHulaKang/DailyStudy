myexe: test.o
	ld -m elf_i386 test.o -o myexe

test.o:test.asm
	nasm -f elf test.asm