bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db 'abcdef'
    len equ ($-s)
    d times len db 0
    
; Se da un sir de caractere s.
; Se cere sirul de caractere d obtinut prin copierea sirului s.
segment code use32 class=code
    start:
        mov ecx, len  ; ecx = len
        jecxz sfarsit
        mov esi, 0
        
    repeta:
        mov al, [s+esi]
        mov [d+esi], al
        inc esi
    loop repeta
    
     sfarsit:
        push dword 0        ; push the parameter for exit onto the stack
        call [exit]         ; call exit to terminate the program
