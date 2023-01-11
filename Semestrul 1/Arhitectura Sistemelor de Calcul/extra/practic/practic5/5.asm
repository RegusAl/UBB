bits 32

global start

extern exit, fread, fopen, fclose, printf
import exit msvcrt.dll
import fread msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    nume_fisier db "r1.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    len equ 50
    text_decodat times len db 0
    text times len db 0
    

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
        
        ; citire fisier
        push dword [descriptor_fisier]
        push dword len
        push dword 1
        push dword text
        call [fread]
        add esp, 4*4
        
        ; decodare propozitie
        mov esi, 0
        repeta:
          
            mov al, [text+esi]
            
            cmp al, 0
            je final
            
            cmp al, ' '
            je peste
            
            cmp al, '.'
            je peste
            
            cmp al, 'A'
            jne nu_A
            mov al, 'Z'
            jmp peste
            
            nu_A:
            cmp al, 'a'
            jne nu_a
            mov al, 'z'
            jmp peste
            
            nu_a:
            cmp al, 'B'
            jne nu_B
            mov al, 'Y'
            jmp peste
            
            nu_B:
            cmp al, 'b'
            jne nu_b
            mov al, 'y'
            jmp peste
            
            nu_b:

            sub al, 2
            
            peste:
            
            mov [text_decodat+esi], al
            inc(esi)
            
        jmp repeta
        
        
        final:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
        
        ; afisare
        push dword text_decodat
        call [printf]
        add esp, 1*4
        
    push dword 0
    call [exit]