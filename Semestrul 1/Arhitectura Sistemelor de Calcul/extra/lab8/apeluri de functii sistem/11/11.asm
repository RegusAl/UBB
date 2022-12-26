; Sa se citeasca de la tastatura un numar in baza 16 si sa se afiseze valoarea acelui numar in baza 10.
; Exemplu: Se citeste: 1D; se afiseaza: 29
bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    numar dd 0
    citire_numar db "numar in hexa = ", 0
    format db "%x", 0
    afisare db "Numarul in decimal este: %d", 0

segment code use32 class=code
    start:
    
        ; numar = 
        push dword citire_numar
        call [printf]
        add esp, 1*4
        
        ; citire numar in hexa
        push dword numar
        push dword format
        call [scanf]
        add esp, 2*4
        
        ; afisare numar in decimal
        push dword [numar]
        push dword afisare
        call [printf]
        add esp, 2*4
    
    push dword 0
    call [exit]
