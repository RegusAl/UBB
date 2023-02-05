; calculeaza factorialul uni numar N dat de la tastatura
bits 32

global start

extern exit, printf, scanf, factorial
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    n dd 0
    format_prompt db "N = ", 0
    afisare_factorial db "Factorial = %d", 10, 13, 0
    format_dec db "%d", 0
    
segment code use32 class=code
    start:
    
        ; citire n 
        push dword format_prompt
        call [printf]
        add esp, 1*4
        
        push dword n
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; apelare factorial din modul.asm
        push dword [n]          ; punem n pe stiva
        call factorial          ; apelam factorial din modul.asm
        add esp, 1*4            ; eliberam stiva
        
        push dword eax
        push dword afisare_factorial
        call [printf]
        add esp, 2*4
        
    push dword 0
    call [exit]

