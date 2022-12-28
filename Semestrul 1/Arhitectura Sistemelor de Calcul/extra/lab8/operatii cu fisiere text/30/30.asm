; Se da un nume de fisier (definit in segmentul de date). Sa se creeze un fisier cu numele dat, apoi sa se citeasca de la tastatura cuvinte pana cand se citeste de la tastatura caracterul '$'. Sa se scrie in fisier doar cuvintele care contin cel putin o cifra.  
bits 32
global start

extern exit, fopen, fprintf, fclose, gets
import exit msvcrt.dll
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll
import gets msvcrt.dll

segment data use32 class=data
    nume_fisier db "fisier.txt", 0
    mod_acces db "w", 0
    descriptor_fisier dd -1
    cuvant resb 30
    format_str db "%s", 0
    spatiu db " ", 0

segment code use32 class=code
    start:
    
        ; deschidere fisier
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        ; verificare fisier
        mov [descriptor_fisier], eax
        cmp eax, 0
        je final
        
        repeta:
            
            ; citim cuvantul
            push dword cuvant
            call [gets]
            add esp, 1*4
            
            ; citim cuvinte pana dam de caracterul '$'
            cmp byte [cuvant], '$'
            je gata
            
            ; vedem daca cel putin un caracter din cuvant este cifra
            mov esi, 0
            cifra:
                cmp byte [cuvant+esi], 0
                je peste
                
                cmp byte [cuvant+esi], '0'
                jl nu_cifra
                
                cmp byte [cuvant+esi], '9'
                jg nu_cifra
                
                push dword cuvant
                push dword [descriptor_fisier]
                call [fprintf]
                add esp, 2*4
            
                push dword spatiu
                push dword [descriptor_fisier]
                call [fprintf]
                add esp, 2*4
                
                jmp peste
                
                nu_cifra:
                inc(esi)
            jmp cifra
       
            peste:

        jmp repeta
        
        gata:
        
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
        
    final:
    
    push dword 0
    call [exit]