;  Sa se citeasca de la tastatura un numar in baza 10 si sa se afiseze valoarea acelui numar in baza 16 
bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    a dd 0
    mesaj_a db "a = ", 0
    format_dec db "%d", 0
    afisare db "Numarul %d in hexa este %xh", 0

segment code use32 class=code
    start:
        
        ; a = 
        push dword mesaj_a
        call [printf]
        add esp, 1*4
        
        ; citire a
        push dword a
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; afisare
        push dword [a]
        push dword [a]
        push dword afisare
        call [printf]
        add esp, 3*4
        
    push dword 0
    call [exit]