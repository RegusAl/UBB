; Se da un fisier text. Sa se citeasca continutul fisierului, sa se contorizeze numarul de consoane si sa se afiseze aceasta valoare. Numele fisierului text este definit in segmentul de date. 
bits 32
global start

extern exit, fopen, fread, fclose, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    nume_fisier db "consoane.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    len equ 100
    text times len db 0
    format_string db "%s", 0
    numar_consoane dd 0
    consoane db "bcdfghjklmnpqrstvxyzBCDFGHJKLMNPQRSTVXYZ", 0
    afisare_format db "Textul are %d consoane", 0
    
segment code use32 class=code
    start:
        
        ; deschidere fisier
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
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
        
        ; numarare vocale
        mov esi, 0
        cld 
        mov ebx, 0
        
        repeta:
        
            mov edi, 0
            mov ecx, 40
            
            ; loop pentru a vedea daca text[esi] = text[edi]
            consoane_loop:
                mov dl, [consoane+edi]
                cmp [text+esi], dl
                je consoana
                inc(edi)
            loop consoane_loop
            
            jmp peste
            
            consoana:
                add ebx, 1
            
            peste:
                inc(esi)
                
        cmp byte [text+esi], 0
        jne repeta
        
        mov [numar_consoane], ebx
        
        ; afisare numar de vocale in consola
        push dword [numar_consoane]
        push dword afisare_format
        call [printf]
        add esp, 2*4
        
    
    final:
    call [exit]
    push dword 0