; Se citeste din fisierul numere.txt un sir de numere. Sa se determine sirul destinatie D care contine numerele din sirul initial cu valorile dublate dar in ordine inversa din sirul initial. Sa se afiseze sirul obtinut pe ecran.
;   Ex: s: 12, 2, 4, 5, 0, 7 => 14, 0, 10, 8, 4, 24
bits 32

global start

extern exit, fopen, fread, fclose, printf, fscanf
import exit msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
import fscanf msvcrt.dll

%include "modul.asm"

segment data use32 class=data
    nume_fisier db 'numere.txt', 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    ;sir times 10 dd 0
    d times 10 dd 0
    numar dd 0
    format_dec db '%d', 0
    format_char db '%c', 0
    space equ ' '
    contor dd 0


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
        
        mov esi, 0
        mov edi, d
        cld
        repeta:
        
            
            push dword numar
            push dword format_dec
            push dword [descriptor_fisier]
            call [fscanf]
            add esp, 4*3
            
            cmp eax, -1
            je final
            
            mov eax, [numar]
            cmp eax, space
            je repeta
            
            push dword [numar]
            call dublare
            
            ;add eax, eax
            stosd
            
            ; push dword eax
            ; push dword format_dec
            ; call [printf]
            ; add esp, 2*4
            
            ; push dword space
            ; push dword format_char
            ; call [printf]
            ; add esp, 2*4
            
            add dword [contor], 1
        
        jmp repeta
                 
        final:
        
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
        
        mov edi, d
        cld
        mov ecx, [contor]
        afisare:
            push ecx

            ;lodsd
            push dword [d+ecx*4-4]
            push dword format_dec
            call [printf]
            add esp, 2*4
            
            push dword space
            push dword format_char
            call [printf]
            add esp, 2*4
            
            pop ecx       
        loop afisare
           
    push dword 0
    call [exit]