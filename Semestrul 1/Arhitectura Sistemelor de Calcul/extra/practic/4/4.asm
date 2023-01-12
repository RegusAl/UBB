; Se citeste o propozitie de la tastatura. Sa se numere literele din fiecare cuvant si sa se afiseze aceste numere pe ecran.
bits 32

global start

extern exit, printf, gets, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import gets msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    propozitie times 100 db 0
    contor dd 0
    format_dec db "%d ", 0
    
segment code use32 class=code
    start:
    
        ; citire propozitie de la tastatura
        push dword propozitie
        call [gets]
        add esp, 1*4
        
        ; numarare litere din fiecare cuvant
        mov esi, propozitie
        cld
        repeta:
            lodsb       ; al = text[esi]
            
            cmp al, ' '
            je cuvant_gasit
            
            cmp al, '.'
            je punct
            
            add dword [contor], 1
            
            jmp peste 
            
            cuvant_gasit:
            
            push dword [contor]
            push dword format_dec
            call [printf]
            add esp, 2*4
            
            mov dword [contor], 0
            
            peste:
            
        jmp repeta
        
        punct:
        
        push dword [contor]
        push dword format_dec
        call [printf]
        add esp, 2*4

    
    push dword 0
    call [exit]