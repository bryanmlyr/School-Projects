BITS 64

global rindex

section .text

rindex:
	push rbp		;prologue
	mov rbp, rsp		;prologue
	mov rcx, -1
	mov r12, -1
	cmp rdi, 0
	je _error
	cmp rdx, 0
	je _error
	jmp _while

_mov_rcx:
	mov rcx, r12

_while:
	inc r12
	cmp BYTE [rdi + r12], 0
	je end
	cmp BYTE [rdi + r12], sil
	je _mov_rcx
	jne _while

end:
	cmp rcx, -1
	je _error
	mov rax, rdi
	add rax, rcx

	pop r12
	pop rcx
	mov rsp, rbp		;epilogue
	pop rbp			;epilogue
	ret

_error:
	mov rax, 0

	pop r12
	pop rcx
	mov rsp, rbp		;epilogue
	pop rbp			;epilogue
	ret