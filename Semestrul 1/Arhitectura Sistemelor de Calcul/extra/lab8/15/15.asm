; Sa se citeasca de la tastatura doua numere a si b (in baza 10) si sa se calculeze a+b. Sa se afiseze rezultatul adunarii in baza 16. 
bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    a dd 0
    b dd 0
    mesaj_a db "a = ", 0
    mesaj_b db "b = ", 0
    format_dec db "%d"
    afisare db "Rezultatul este %xh"

segment code use32 claaa=code
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
        
        ; b = 
        push dword mesaj_b
        call [printf]
        add esp, 1*4
        
        ; citire b
        push dword b
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; a + b
        mov eax, [a]
        add eax, [b]
        
        ; afisare rezultat
        push eax
        push dword afisare
        call [printf]
        add esp, 2*4
    
    push dword 0
    call [exit]