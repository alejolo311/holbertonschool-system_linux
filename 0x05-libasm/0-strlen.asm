BITS 64
	global asm_strlen

	section .text

asm_strlen:
	push rbp
	mov rbp, rsp
	mov rax, 0
	jmp check

body:
	inc rax
	inc rdi

check:
	cmp byte [rdi], 0
	jne body
	mov rsp, rbp
	pop rbp
	ret
