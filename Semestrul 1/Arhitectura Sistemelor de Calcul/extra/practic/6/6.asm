; Se citesc din fisierul numere.txt mai multe numere (pare si impare). Sa se creeze 2 siruri rezultat N si P astfel: N - doar numere impare si P - doar numere pare. Afisati cele 2 siruri rezultate pe ecran.
bits 32

global start

extern exit, printf, fopen, fclose, fscanf
import exit msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fscanf msvcrt.dll

segment data use32 class=data
    nume_fisier db "numere.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    format_dec db "%d", 0
    N times 20 dd 0
    P times 20 dd 0
    numar dd 0
    doi dd 2
    afisare_numere db "%d ", 0
    endline db " ", 10, 13, 0
    
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
        
        ; citire numere
        mov esi, 0
        mov edi, 0
        repeta:
        
            push dword numar
            push dword format_dec
            push dword [descriptor_fisier]
            call [fscanf]
            add esp, 3*4
            
            cmp eax, -1
            je gata_repeta
            
            mov eax, [numar]
            mov edx, 0
            div dword [doi]
            
            mov eax, [numar]
            cmp edx, 0
            je par
            
            mov [N+edi], eax
            add edi, 4
            
            jmp peste
            
            par:
            
            mov [P+esi], eax
            add esi, 4
            
            peste:
            
        jmp repeta
        
        gata_repeta:
        
        ; afisare numere impare
        mov esi, 0
        impare:
        
            cmp byte [N+esi], 0
            je gata_impare
            
            push dword [N+esi]
            push dword afisare_numere
            call [printf]
            add esp, 2*4
            
            add esi, 4
        
        jmp impare
        
        gata_impare:
        
        push dword endline
        call [printf]
        add esp, 1*4
        
        mov esi, 0
        pare:
        
            cmp byte [P+esi], 0
            je gata_pare
            
            push dword [P+esi]
            push dword afisare_numere
            call [printf]
            add esp, 2*4
            
            add esi, 4
        
        jmp pare
        
        gata_pare:

        final:
        ; inchidere fisier 
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
    
    push dword 0
    call [exit]