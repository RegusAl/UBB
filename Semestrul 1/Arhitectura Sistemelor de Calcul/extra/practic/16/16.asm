; Se citesc nr din fisier, sa se faca suma nr mai mici decat 8 si sa se afiseze pe ecran.
bits 32

global start

extern exit, printf, fscanf, fopen, fclose
import exit msvcrt.dll
import printf msvcrt.dll
import fscanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll

segment data use32 class=data
    nume_fisier db "fisier.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    format_dec db "%d", 0
    numar dd 0
    suma dd 0

segment code use32 class=code
    start:
    
        ; deschidere fisier
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        ; verificare fisier
        cmp eax, 0
        je final
        mov [descriptor_fisier], eax
        
        repeta:

            push dword numar
            push dword format_dec
            push dword [descriptor_fisier]
            call [fscanf]
            add esp, 3*4
            
            cmp eax, -1
            je gata
            
            mov eax, [numar]
            cmp eax, 8
            jg peste
            
            add dword [suma], eax
            mov dword [numar], 0
            peste:
        
        jmp repeta

        gata:
        
        push dword [suma]
        push dword format_dec
        call [printf]
        add esp, 2*4

        final:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
        
    
    push dword 0
    call [exit]