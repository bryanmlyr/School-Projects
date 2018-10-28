BITS 64

global strcmp

section .text
strcmp:
	push rbp
	mov rbp, rsp

_while:
	mov r12b, [rdi]
	mov r13b, [rsi]
	cmp r12b, 0
	je _end
	cmp r13b, 0
	je _end
	cmp r12b, r13b
	jne _end
	inc rdi
	inc rsi
	jmp _while

_end:
	sub r12b, r13b
	movsx rax, r12b

	mov rsp, rbp
	pop rbp
	ret