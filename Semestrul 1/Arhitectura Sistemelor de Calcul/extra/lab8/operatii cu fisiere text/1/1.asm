; Se da un fisier text. Sa se citeasca continutul fisierului, sa se contorizeze numarul de vocale si sa se afiseze aceasta valoare. Numele fisierului text este definit in segmentul de date. 
bits 32
global start

extern exit, fopen, fread, fclose, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    nume_fisier db "vocale.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    numar_vocale dd 0
    len equ 100
    text times len db 0
    format_string db "%s", 0
    afisare_format db "Textul are %d vocale", 0
    
segment code use32 class=code
    start:
        
        ; deschidem fisierul
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        mov [descriptor_fisier], eax
        
        cmp eax, 0
        je final
        
        ; citim textul din fisier
        push dword [descriptor_fisier]
        push dword len
        push dword 1
        push dword text
        call [fread]
        add esp, 4*4
        
        ; inchidem fisierul
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
        
        ; numarare vocale
        mov esi, 0
        cld 
        mov ebx, 0
        repeta:
        
            cmp byte [text+esi], 'a'
            je numara
            
            cmp byte [text+esi], 'e'
            je numara
        
            cmp byte [text+esi], 'i'
            je numara
        
            cmp byte[text+esi], 'o'
            je numara
            
            cmp byte[text+esi], 'u'
            je numara
            
            cmp byte[text+esi], 'A'
            je numara
            
            cmp byte[text+esi], 'E'
            je numara
            
            cmp byte[text+esi], 'I'
            je numara
            
            cmp byte[text+esi], 'O'
            je numara
            
            cmp byte[text+esi], 'U'
            je numara
            
            jmp peste
            
            numara:
                add ebx, 1
                
            peste:
                inc(esi)
                
        cmp byte [text+esi], 0
        jne repeta
        
        mov [numar_vocale], ebx
        
        ; afisare numar de vocale in consola
        push dword [numar_vocale]
        push dword afisare_format
        call [printf]
        add esp, 2*4
        
    final:
    
    push dword 0
    call [exit]