;  Se da un fisier text. Sa se citeasca continutul fisierului, sa se contorizeze numarul de caractere speciale si sa se afiseze aceasta valoare. Numele fisierului text este definit in segmentul de date. 
bits 32
global start

extern exit, fopen, fread, fclose, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    nume_fisier db "caractere_speciale.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    len equ 100
    text times len db 0
    caractere_speciale db "~`!@#$%^&*()_+-={[}]\|:;'<,.>/?"
    afisare_format db "Textul are %d caractere speciale", 0

segment code use32 class=code
    start:
        
        ; deschidere fisier
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        ; verificare descriptor_fisier
        mov [descriptor_fisier], eax
        cmp eax, 0
        je final
    
        ; citire text din fisiere
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
        
        ; numarare caractere speciale
        mov esi, 0
        cld
        mov ebx, 0
        repeta:
        
            mov edi, 0
            mov ecx, 31
            caractere_speciale_loop:
                mov dl, [caractere_speciale+edi]
                inc(edi)
                cmp dl, [text+esi]
                je numarare
                
            loop caractere_speciale_loop
            
            jmp peste 
            
            numarare:
                add ebx, 1
            
            peste:
                inc(esi)
        
        cmp byte [text+esi], 0
        jne repeta
        
        ; afisarea numarului de caractere speciale
        push ebx
        push dword afisare_format
        call [printf]
        add esp, 2*4
    
    final:
    
    push dword 0
    call [exit]