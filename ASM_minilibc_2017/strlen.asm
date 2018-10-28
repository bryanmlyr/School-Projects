BITS 64

global strlen

section .text
strlen:
	push rbp
	mov rbp, rsp

	push rcx
	mov rcx, -1

	call _while

_while:
	inc rcx
	cmp BYTE [rdi + rcx], 0
	jne _while

	mov rax, rcx
	pop rcx
	leave
	ret