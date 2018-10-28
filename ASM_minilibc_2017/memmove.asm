BITS 64

global memmove

section .text
memmove:
	push rbp
	mov rbp, rsp

	mov rcx, 0

	cmp rdi, 0
	je end

	cmp rsi, 0
	je end

	cmp rdx, rcx
	je end

_while:
	cmp rcx, rdx
	je end
	mov r12b, [rsi + rcx]
	mov BYTE [rdi + rcx], r12b
	inc rcx
	jmp _while

end:
	mov rax, rdi
	mov rsp, rbp
	pop rbp
	ret