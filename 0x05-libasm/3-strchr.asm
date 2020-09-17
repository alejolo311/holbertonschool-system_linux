BITS 64
    global asm_strchr

    section .text
asm_strchr:
    push    rbp
    mov     rbp, rsp
    xor     rax, rax
strchr_loop:
    mov     al, BYTE [rdi]
    cmp     BYTE [rdi], sil
    jz      match
    cmp     BYTE [rdi], 0
    jz      end
    inc     rdi
    jmp     strchr_loop
match:
    mov     rax, rdi
end:
    mov rsp, rbp
    pop rbp
    ret
