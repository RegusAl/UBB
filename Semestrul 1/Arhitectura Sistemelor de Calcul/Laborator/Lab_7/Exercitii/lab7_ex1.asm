bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db 'a', 'b', 'c', 'd', 'e', 'f'
    len equ ($-s)
    d times len db 0
    
; Se da un sir de caractere s.
; Se cere sirul de caractere d obtinut prin copierea sirului s, folosind instructiuni pe siruri.
segment code use32 class=code
    start:
        mov ecx, len
        jecxz sfarsit
        cld
        mov esi, s
        mov edi, d
        repeta:
            ; lodsb
            ; stosb
            movsb
        loop repeta
        sfarsit:
        ; exit(0)
        push dword 0        ; push the parameter for exit onto the stack
        call [exit]         ; call exit to terminate the program
