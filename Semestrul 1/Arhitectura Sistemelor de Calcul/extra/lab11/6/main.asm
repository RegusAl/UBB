; Se citesc trei siruri de caractere. Sa se determine si sa se afiseze rezultatul concatenarii lor.
bits 32
global start

extern exit, printf, concatenare
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    s1 db "Ana are vreo", 0
    len1 equ $-s1
    s2 db "312353 ", 0
    len2 equ $-s2
    s3 db "portocale", 0
    len3 equ $-s3
    sir_final times 100 db 0

segment code use32 class=code
    start:
        
        push dword len1
        push dword len2
        push dword len3
        push dword sir_final
        push dword s3
        push dword s2
        push dword s1
        call concatenare
        add esp, 4*7
    
        push dword sir_final
        call [printf]
        add esp, 1*4
        
        
    push dword 0
    call [exit]