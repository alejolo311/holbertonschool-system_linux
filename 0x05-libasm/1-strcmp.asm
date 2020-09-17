BITS 64
	global asm_strcmp

	section .text

asm_strcmp:
	push rbp
	mov rbp, rsp
	push rdx

strcmp_loop:
	mov dl,	[rdi]
	mov dh,	[rsi]
	cmp dl,	dh
	jl less
	jg greater
	cmp dl,	0h
	je equal
	inc rdi
	inc rsi
	jmp strcmp_loop

less:
	mov eax, -1h
	jmp end

greater:
	mov eax, 1h
	jmp end

equal:
	mov eax, 0h

end:
	pop rdx
	mov rsp, rbp
	pop rbp
	ret
