; Se citesc de la tastatura numere (in baza 10) pana cand se introduce cifra 0. Determinaţi şi afişaţi cel mai mare număr dintre cele citite.
bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    max resd 1
    x dd 0
    format_dec db "%d", 0
    afisare db "Numarul maxim este: %d", 0
    

segment code use32 class=code
    start:
        
        ; citire numere
        repeta:
            push dword x
            push dword format_dec
            call [scanf]
            add esp, 2*4
            mov eax, [x]
            cmp eax, 0
            je peste
            cmp eax, [max]
            jl mai_mic
            mov [max], eax
            mai_mic:
        jmp repeta
    
        peste:
        
        push dword [max]
        push dword afisare
        call [printf]
        add esp, 2*4
    
    push dword 0
    call [exit]