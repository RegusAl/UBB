;  Se da un fisier text care contine litere, spatii si puncte. Sa se citeasca continutul fisierului, sa se determine numarul de cuvinte si sa se afiseze pe ecran aceasta valoare. (Se considera cuvant orice secventa de litere separate prin spatiu sau punct) 
bits 32
global start

extern exit, fopen, fread, fclose, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    nume_fisier db "fisier.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    len equ 100
    text times len db 0
    nr_cuvinte dd 0
    afisare db "%d cuvinte", 0
    

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
        
        ; citire text din fisier
        push dword [descriptor_fisier]
        push dword len
        push dword 1
        push dword text
        call [fread]
        add esp, 4*4
        
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
        
        mov esi, text
        mov bl, 0
        cld
        repeta:
            lodsb   ; al = text[esi]
            
            cmp al, 0
            je gata
            
            cmp bl, '.'
            je peste
            
            cmp al, ' '
            je numara
            
            cmp al, '.'
            je numara
            
            jmp peste
            
            numara:
                add dword [nr_cuvinte], 1
        
            peste:
            mov bl, al
        
        jmp repeta
        
        gata:
        
        push dword [nr_cuvinte]
        push dword afisare
        call [printf]
        add esp, 2*4
        
    final:
    
    push dword 0
    call [exit]