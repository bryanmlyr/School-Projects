BITS 64

global write

section .text

write:
	mov rax, 1
	syscall
	ret