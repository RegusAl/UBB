; Se da un numar natural negativ a (a: dword). Sa se afiseze valoarea lui in baza 10 si in baza 16, in urmatorul format: "a = <base_10> (baza 10), a = <base_16> (baza 16)" 
bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    a dd 0
    mesaj_a db "a = ", 0
    format db "%d", 0
    afisare db "a = %d (base 10), a = %x (base 16)", 0
    
    
segment code use32 class=code
    start:
    
        ; a = 
        push dword mesaj_a
        call [printf]
        add esp, 1*4
    
        ; citire a
        push dword a
        push dword format
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