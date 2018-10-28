BITS 64

global strchr

section .text

strchr:
	push rbp
	mov rbp, rsp

_while:
	cmp [rdi], sil
	je found
	cmp BYTE [rdi], 0
	je not_found
	cmp [rdi], sil
	inc rdi
	jne _while

not_found:
	mov rax, 0

	pop rdi
	mov rsp, rbp
	pop rbp
	ret

found:
	mov rax, rdi

	pop rdi
	mov rsp, rbp
	pop rbp
	ret

