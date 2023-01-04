bits 32

global start

extern exit, fread, fopen, fclose, printf
import exit msvcrt.dll
import fread msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    nume_fisier db "r2.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    len equ 100
    sir times len db 0
    text times len db 0
    format_str db "%s", 0
    format_chr db "%c", 0

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
        
        ; citire fisier
        push dword [descriptor_fisier]
        push dword len
        push dword 1
        push dword text
        call [fread]
        add esp, 4*4
        
        ; descifrare mesaj
        mov esi, text
        mov edi, sir
        cld
        repeta:
            lodsb   ; al = text[esi]
            
            cmp al, 0
            je final
            
            cmp al, ' '
            je spatiu
            
            cmp al, 'A'
            jne nu_A
            mov al, 'X'
            
            nu_A:
            cmp al, 'a'
            jne nu_a
            mov al, 'a'
            
            nu_a:
            cmp al, 'B'
            jne nu_B
            mov al, 'Y'
            
            nu_B:
            cmp al, 'b'
            jne nu_b
            mov al, 'y'
            
            nu_b:
            cmp al, 'C'
            jne nu_C
            mov al, 'Z'
            
            nu_C:
            cmp al, 'c'
            jne nu_c
            mov al, 'z'
            
            nu_c:
            
            sub al, 3
            
            spatiu:
            stosb
        
        jmp repeta
    
    final:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
        
        ; afisare text descifrat
        push dword sir
        call [printf]
        add esp, 1*4
    
    
    push dword 0
    call [exit]