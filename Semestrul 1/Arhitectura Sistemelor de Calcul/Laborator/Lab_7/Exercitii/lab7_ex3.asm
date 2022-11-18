bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s1 dw 1234h, 67abh, 89cdh
    
    s2 dw 2345h, 5678h, 4567h
    len equ ($-s2)/2
    d times len db 0
    

; Se dau doua siruri de cuvinte s1 si s2.
; Se cere sirul de cuvinte d obtinut in interpretarea cu semn, astfel:
; - d[i] = s1[i], daca s1[i] > s2[i]
; - d[i] = s2[i], altfel.
segment code use32 class=code
    start:
        mov ecx, len
        jecxz final
        mov esi, s1
        mov edi, s2
        repeta:
            cmpsw
            jg mai_mare ; ax>bx in iterpretarea cu semn
            mai_mic:
                sub edi, 2
                mov ax, [edi]
                mov, [d+ebx], ax\
                add ebx, 2
                add edi, 2
                jmp next
            mai_mare:
                sub esi, 2
                lodsw
                mov [d+ebx], ax
                add ebx, 2
            next:
        loop repeta       
        final:
        ; exit(0)
        push dword 0        ; push the parameter for exit onto the stack
        call [exit]         ; call exit to terminate the program
