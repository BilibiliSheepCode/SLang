[BITS 64]
[SECTION .equs]
stdout equ 1
stdin equ 2
[SECTION .bss]
_putchar_ARG1_ resb 8
_print_ARG1_ resb 8
[SECTION .data]
_Data1_ db "Hello,world!",0x0a,0x00
[SECTION .text]
global _start
_start:
    call Main
    mov rax,1
    int 0x80
Main:
    mov rax,0
    mov rbx,0
    mov rcx,0
    mov rdx,0
    mov qword[_print_ARG1_],_Data1_
    call print
    mov rbx,0
    ret
putchar:
    mov rcx,qword [_putchar_ARG1_]
    mov rdx,1
    mov rax,4
    mov rbx,stdout
    int 0x80
    ret
print:
    mov rax,[_print_ARG1_]
    mov qword [_putchar_ARG1_],rax
    call putchar
    mov rax,qword [_print_ARG1_]
    mov bl,[rax]
    cmp bl,0
    je return
    mov rcx,[_print_ARG1_]
    add rcx,1
    mov qword [_print_ARG1_],rcx
    jmp print
return:
    ret