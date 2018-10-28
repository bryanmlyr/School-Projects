BITS 64

global strncmp

section .text
strncmp:
	push rbp
	mov rbp, rsp

	push rcx
	mov rcx, 0

	cmp rdx, 0
	je _zero

_while:
	mov r12b, [rdi]
	mov r13b, [rsi]
	cmp r12b, 0
	je _end
	cmp r13b, 0
	je _end
	cmp r12b, r13b
	jne _end

	inc rcx
	cmp rcx, rdx
	je _end

	inc rdi
	inc rsi
	jmp _while

_end:
	sub r12b, r13b
	movsx rax, r12b

	pop rcx

	mov rsp, rbp
	pop rbp
	ret

_zero:
	mov rax, 0
	pop rcx
	mov rsp, rbp
	pop rbp
	ret
