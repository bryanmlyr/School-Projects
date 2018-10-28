BITS 64

global memset

section .text
memset:
	push rbp		;prologue
	mov rbp, rsp

	mov rcx, 0

_while:
	mov BYTE [rdi + rcx], sil
	inc rcx
	cmp rcx, rdx
	jne _while

end:
	mov rax, rdi

	mov rsp, rbp		;epilogue
	pop rbp
	ret