; Sa citesti un nume de fisier de la tastatura, sa deschizi fisieru, sa numeri cate caractere is in fisier, si apoi sa pui nr ala la capatu fisierului.
bits 32

global start

extern exit, fopen, fclose, fprintf, gets, fscanf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import gets msvcrt.dll
import fscanf msvcrt.dll

segment data use32 class=data
    nume_fisier times 20 db 0
    mod_acces_r db "r", 0
    mod_acces_a db "a", 0
    descriptor_fisier dd -1
    format_char db "%c", 0
    format_dec db "%d", 0
    caracter db 0
    contor dd 0


segment code use32 class=code
    start:
    
        ; citim numele fisierului
        push dword nume_fisier
        call [gets]
        add esp, 1*4
    
        ; deschidere fisier
        push dword mod_acces_r
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        ; verificare fisier
        cmp eax, 0
        je final
        mov [descriptor_fisier], eax
        
        ; citim caracterele si le numaram
        repeta:
        
            ; citire caracter
            push dword caracter
            push dword format_char
            push dword [descriptor_fisier]
            call [fscanf]
            add esp, 3*4
            
            cmp eax, -1
            je final
            
            add dword [contor], 1
           
        jmp repeta

        final:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
        
        
        ; deschidere fisier
        push dword mod_acces_a
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        ; verificare fisier
        cmp eax, 0
        je final
        mov [descriptor_fisier], eax
                
        push dword [contor]
        push dword format_dec
        push dword [descriptor_fisier]
        call [fprintf]
        add esp, 3*4
        
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
        
    push dword 0
    call [exit]