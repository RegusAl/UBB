; Se citesc de la tastatura doua numere a si b. Sa se calculeze valoarea expresiei (a-b)*k, k fiind o constanta definita in segmentul de date. Afisati valoarea expresiei (in baza 16). 
bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    a dd 0
    b dd 0
    k dd 2
    mesaj_a db "a = ", 0
    mesaj_b db "b = ", 0
    format_dec db "%d", 0
    afisare db "rezultat: %xh"

segment code use32 class=code
    start:
        
        ; a =
        push dword mesaj_a
        call [printf]
        add esp, 1*4
        
        ; citim a
        push dword a
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; b =
        push dword mesaj_b
        call [printf]
        add esp, 1*4
        
        ; citim b
        push dword b
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; edx:eax = (a - b) * k
        mov eax, [a]
        sub eax, [b]
        imul dword [k]
        
        ; afisare
        push edx
        push eax
        push dword afisare
        call [printf]
        add esp, 3*4
        
    push dword 0
    call [exit]