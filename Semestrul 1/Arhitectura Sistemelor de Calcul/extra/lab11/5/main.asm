; Se cere se se citeasca numerele a, b si c ; sa se calculeze si sa se afiseze a+b-c.
bits 32
global start

extern exit, printf, scanf, operatie
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    a dd 0
    b dd 0
    c dd 0
    format_dec db "%d"
    format_afisare db "a + b - c = %d", 0
    format_a db "a = ", 0
    format_b db "b = ", 0
    format_c db "c = ", 0
    
segment code use32 class=code
    start:
        
        push dword format_a
        call [printf]
        add esp, 1*4
        
        push dword a
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        push dword format_b
        call [printf]
        add esp, 1*4
        
        push dword b
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        push dword format_c
        call [printf]
        add esp, 1*4
        
        push dword c
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; esp + 16
        mov eax, [c]
        push dword eax
        ; esp + 12
        mov eax, [b]
        push dword eax
        ; esp + 8
        mov eax, [a]
        push dword eax
        ; esp + 4
        mov eax, 0
        push eax
        
        call operatie

        pop eax
        add esp, 3*4
        
        push dword eax
        push dword format_afisare
        call [printf]
        add esp, 2*4
    
    push dword 0
    call [exit]