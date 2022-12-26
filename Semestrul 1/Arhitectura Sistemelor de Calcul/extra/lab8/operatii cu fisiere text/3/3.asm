;  Se da un fisier text. Sa se citeasca continutul fisierului, sa se contorizeze numarul de cifre pare si sa se afiseze aceasta valoare. Numele fisierului text este definit in segmentul de date. 
bits 32
global start

extern exit, fopen, fread, printf, fclose
import exit msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll
import fclose msvcrt.dll

segment data use32 class=data
    nume_fisier db "cifre_pare.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    len equ 100
    text times len db 0
    cifre_pare db "02468", 0
    afisare_format db "Textul contine %d cifre pare", 0
   
segment code use32 class=code
    start:
   
        ; deschidere fisier
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        ; verificare continu fisier
        mov [descriptor_fisier], eax
        cmp eax, 0
        je final
        
        ; citire din fisier
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
        
        ; numarare cifre pare
        mov esi, 0
        cld
        mov ebx, 0
  
        repeta:
                
            mov ecx, 5
            mov edi, 0
            ; comparam pe rand text[esi] cu cifre_pare[edi]
            numere_pare_loop:
                mov dl, [cifre_pare+edi]
                cmp [text+esi], dl
                je cifra_para
                inc(edi)
            loop numere_pare_loop
        
            jmp peste
            
            cifra_para:
                add ebx, 1
            
            peste:
                inc(esi)
            
        cmp byte [text+esi], 0
        jne repeta   

        ; afisare numarul de cifre pare in fisier
        push ebx
        push dword afisare_format
        call [printf]
        add esp, 2*4
        
    final:
    
    push dword 0
    call [exit]