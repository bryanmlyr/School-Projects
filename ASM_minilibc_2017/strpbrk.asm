BITS 64

global strpbrk

section .text

strpbrk:
	push rbp
	mov rbp, rsp
	mov rcx, 0

	cmp rdi, 0
	je not_found 
	cmp rsi, 0
	je not_found

_while:
	mov r12b, [rsi + rcx]
	cmp [rdi], r12b
	je found
	inc rcx
	cmp BYTE [rsi + rcx], 0
	jne _while

	mov rcx, 0
	inc rdi
	cmp BYTE [rdi], 0
	je not_found
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

