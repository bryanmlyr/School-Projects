BITS 64

global read

section .text

read:
	mov rax, 0
	syscall
	ret