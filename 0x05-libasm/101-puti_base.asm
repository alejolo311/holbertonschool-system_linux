BITS 64
	global asm_puti_base

	extern asm_putc

	extern asm_strlen

	section .text

asm_puti_base:
	push rbp
	mov rbp, rsp
	push r12
 	push r13
	push r14
	push r15
    xor r14, r14
	xor r15, r15
	movsx r15, edi
	xor rax, rax
	cmp r15, 0
	jge negative
	imul r15, -1
    mov rdi, 45
	mov r13, 1
    push rsi
	push rbx
	call asm_putc
    pop rbx
	pop rsi
negative:
	mov rdi, rsi
	call asm_strlen
	mov rbx, rax
	cmp rbx, 1
	jnz cero
	mov r14, r15
	un:
	test r15, r15
	jz done_un
	xor rax, rax
	mov al, BYTE [rsi]
    dec r15
	push rax
	jmp un
	done_un:
	xor rax, rax
	jmp while
cero:
	test r15, r15
	jnz while
	movzx rdi, BYTE [rsi]
	call asm_putc
	mov r13, 1
while:
	test rbx, rbx
	jz while_base
	xor rdx, rdx
	test r15, r15
	jz done_while
	mov rax, r15
	div rbx
	mov r15, rax
	xor rax, rax
	mov al, BYTE [rsi + rdx]
	push rax
	inc r14
	jmp while
done_while:
	jmp done_while
while_base:
	xor rdx, rdx
	test r15, r15
	jz done_while_base
	mov rax, r15
	mov rbx, 10
	div rbx
	mov r15, rax
	xor rax, rax
	mov rax, rdx
	add rax, 48
	push rax
	inc r14
	jmp while_base
done_while:
	mov r15, r14
print:
	test r15, r15
	jz done_print
	pop rdi
	after_pop:
	call asm_putc
	dec r15
	jmp print
done_print:
	cmp r13, 1
	jne end
	inc r14
end:
	mov rax, r14
	pop r12
	pop r13
	pop r14
	pop r15
	mov rsp, rbp
	pop rbp
	ret