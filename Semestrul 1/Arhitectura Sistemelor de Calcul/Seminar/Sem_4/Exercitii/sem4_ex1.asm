bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db 'a', 'b', 'c', 'd', 'e', 'f'
    
    
; 1. Se dă un șir de caractere s.
; Să se copieze elementele șirului s într-un alt șir de caractere d,
; folosind instrucțiuni pe șiruri.
segment code use32 class=code
    start:
        
    
        ; exit(0)
        push dword 0        ; push the parameter for exit onto the stack
        call [exit]         ; call exit to terminate the program
