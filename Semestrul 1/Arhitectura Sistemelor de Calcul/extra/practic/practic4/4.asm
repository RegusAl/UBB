bits 32

global start

extern exit, fprintf, scanf, fopen, fclose, gets
import exit msvcrt.dll
import fprintf msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import gets msvcrt.dll

segment data use32 class=data
    nume_fisier db "fisier.txt", 0
    mod_acces db "w", 0
    descriptor_fisier dd -1
    len equ 50
    cuvant times len db 0
    numar dd 0
    contor_vocale dd 0
    format_dec db "%d", 0
    format_string db "%s", 0ah
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
        
        ; citire numar
        push dword numar
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        citeste_cuvant:
        
            ; citire cuvant
            push dword cuvant
            call [gets]
            add esp, 1*4
            
            cmp byte [cuvant], '#'
            je final
            
            mov esi, 0
            mov dword [contor_vocale], 0
            cld
            vocale:
                mov al, [cuvant+esi]
                inc(esi)
                
                cmp al, 0
                je gata
                
                cmp al, 'a'
                je numara
                
                cmp al, 'e'
                je numara
                
                cmp al, 'i'
                je numara
                
                cmp al, 'o'
                je numara
                
                cmp al, 'u'
                je numara
                
                jmp vocale
            
                numara:
                
                add dword [contor_vocale], 1
            
            jmp vocale
            
            gata:
            mov eax, [contor_vocale]
            cmp eax, [numar]
            jl citeste_cuvant
            

            
            ; punere in fisier
            push dword cuvant
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 2*4
            
            push dword spatiu
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 2*4
        
        
        jmp citeste_cuvant
        
        
    final:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
    
    push dword 0
    call [exit]