; Scrieți un program care calculează factorialul unui număr natural n citit de la tastatură.
bits 32

global start

extern exit, printf, scanf, factorial
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    n dd 0
    prompt_n db "n = ", 0
    format_dec db "%d", 0
    afisare db "n! = %d", 0

segment code use32 class=code
    start:
    
        ; citire n de la tastatura
        push dword prompt_n
        call [printf]
        add esp, 1*4
        
        push dword n
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; apelare factorial din modul
        push dword [n]
        call factorial
        add esp, 1*4
        
        ; afisare rezultat ce este in eax
        push dword eax
        push dword afisare
        call [printf]
        add esp, 2*4

    push dword 0
    call [exit]