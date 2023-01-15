; Sa se citeasca de la tastatura un numar n, apoi sa se citeasca mai multe cuvinte, pana cand se citeste cuvantul/caracterul "#". Sa se scrie intr-un fisier text toate cuvintele citite care incep si se termina cu aceeasi litera si au cel putin n litere.
bits 32

global start

extern exit, scanf, fopen, fclose, fprintf
import exit msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll

segment data use32 class=data
    nume_fisier db "fisier.txt", 0
    mod_acces db "a", 0
    descriptor_fisier dd -1
    cuvant times 20 db 0
    n dd 0
    format_string db "%s", 0
    format_dec db "%d", 0
    afisare db "%s ", 0

segment code use32 class=code
    start:
    
        ; citire numar
        push dword n
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
        
        citire_cuvinte:
        
            push dword cuvant
            push dword format_string
            call [scanf]
            add esp, 2*4
            
            cmp byte [cuvant], '#'
            je gata
            
            mov ebx, 0
            mov edx, 0
            mov esi, cuvant
            cld
            numara:
                
                lodsb
                
                cmp al, 0
                je gata_numaratoarea
                
                cmp edx, 0
                jne nu_primul
                
                mov dl, al
                
                nu_primul:
                
                inc(ebx)
                
            jmp numara
            
            gata_numaratoarea:
            
            cmp ebx, [n]
            jne nu_egal
            
            dec(ebx)
            cmp dl, [cuvant+ebx]
            jne nu_egal
            
            push dword cuvant
            push dword afisare
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 3*4
            
            nu_egal:

        jmp citire_cuvinte
        
        gata:
        final:
        
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
    
    push dword 0
    call [exit]