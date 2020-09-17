BITS 64
	global asm_strncmp	; export 'asm_strncmp' function

	section .text

asm_strncmp:
	push rbp
	mov rbp, rsp
	push rcx

strncmp_loop:
	cmp rdx, 0h
	je equal
	mov cl,	[rdi]
	mov ch,	[rsi]
	cmp cl,	ch
	jl less
	jg greater
	cmp cl,	0h
	je equal
	inc rdi
	inc rsi
	dec rdx
	jmp strncmp_loop

less:
	mov eax, -1h
	jmp end

greater:
	mov eax, 1h
	jmp end

equal:
	mov eax, 0h

end:
	pop rcx
	mov rsp, rbp
	pop rbp
	ret