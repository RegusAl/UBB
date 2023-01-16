; Sa se citeasca de la tastatura un nume de fisier si un numar. 
; Sa se citeasca din fisierul dat cuvintele separate prin spatii si sa se afiseze in consola cuvintele care sunt pe pozitiile multipli de numarul citit de la tastatura.
bits 32

global start

extern exit, scanf, fscanf, printf, fopen, fclose
import exit msvcrt.dll
import scanf msvcrt.dll
import fscanf msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll

segment data use32 class=data
    nume_fisier times 20 db 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    numar dd 0
    cuvant times 20 db 0
    contor dd 0
    format_dec db "%d", 0
    format_str db "%s", 0
    format_afisare db "%s ", 0

segment code use32 class=code
    start:
    
        ; citire nume de fisier
        push dword nume_fisier
        push dword format_str
        call [scanf]
        add esp, 2*4
        
        ; citire numar
        push dword numar
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; deschidere fisier
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        ; verificare fisier
        cmp eax, 0
        je final
        mov [descriptor_fisier], eax
        
        ; citim cuvintele din fisier
        citire:
        
            push dword cuvant
            push dword format_str
            push dword [descriptor_fisier]
            call [fscanf]
            add esp, 3*4
        
            cmp eax, -1
            je final
            
            add dword [contor], 1
            
            mov eax, [contor]
            mov edx, 0
            div dword [numar]
            
            cmp edx, 0
            jne peste
            
            push dword cuvant
            push dword format_afisare
            call [printf]
            add esp, 2*4
            
            peste:
        
        jmp citire

        final:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
    
    push dword 0
    call [exit]