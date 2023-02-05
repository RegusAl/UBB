; Scrieți un program care calculează valoarea expresiei x = a+b.
bits 32

global start

extern exit, printf, scanf, addition
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    a dd 0
    b dd 0
    x dd 0
    prompt_a db "a = ", 0
    prompt_b db "b = ", 0
    format_dec db "%d", 0
    afisare db "X = %d", 0

segment code use32 class=code
    start:
    
        ; citire a
        push dword prompt_a
        call [printf]
        add esp, 1*4
        
        push dword a
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; citire b
        push dword prompt_b
        call [printf]
        add esp, 1*4
        
        push dword b
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; apelare addition din modul.asm
        push dword [a]
        push dword [b]
        call addition
        add esp, 2*4
        
        ; afisare rezultat din eax
        push dword eax
        push dword afisare
        call [printf]
        add esp, 2*4
    
    push dword 0
    call [exit]

