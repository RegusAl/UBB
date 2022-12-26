; Sa se citeasca de la tastatura un numar in baza 10 si sa se afiseze valoarea acelui numar in baza 16.
; Exemplu: Se citeste: 28: se afiseaza: 1C 
bits 32
global start

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    a dd 0
    mesaj_a db "a = ", 0
    format db "%d", 0
    rezultat db "Hexa: %x", 0
    
segment code use32 class=code
    start:
    
        ; a = 
        push dword mesaj_a
        call [printf]
        add esp, 1*4
        
        ; citire numar in decimal
        push dword a
        push dword format
        call [scanf]
        add esp, 2*4
        
        ; afisare numar citit in hexa
        push dword [a]
        push dword rezultat
        call [printf]
        add esp, 2*4
    
    push dword 0
    call [exit]