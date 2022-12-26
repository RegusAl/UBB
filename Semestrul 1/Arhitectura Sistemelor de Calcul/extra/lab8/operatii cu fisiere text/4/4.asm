; Se da un fisier text. Sa se citeasca continutul fisierului, sa se contorizeze numarul de cifre impare si sa se afiseze aceasta valoare. Numele fisierului text este definit in segmentul de date. 
bits 32
global start

extern exit, fopen, fread, fclose, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    nume_fisier db "cifre_impare.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    len equ 100
    text times len db 0
    cifre_impare db "13579", 0
    afisare_format db "Textul are %d cifre impare", 0
    
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
        
        mov esi, 0
        cld
        mov ebx, 0
        
        ; numarare cifre imare din text
        repeta:
        
            mov edi, 0
            mov ecx, 5
                
            cifre_impare_loop:
                mov dl, [text+esi]
                cmp dl, [cifre_impare+edi]
                je numara
                inc(edi)
            loop cifre_impare_loop
            
            jmp peste
            
            numara:
                add ebx, 1
            
            peste:
                inc(esi)
        
        cmp byte [text+esi], 0
        jne repeta
        
        ; afisarea cifrelor impare
        push ebx
        push dword afisare_format
        call [printf]
        add esp, 2*4
    
    final:
    
    push dword 0
    call [exit]