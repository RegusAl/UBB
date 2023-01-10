bits 32

global start

extern exit, printf, fscanf, fopen, fclose, fread
import exit msvcrt.dll
import printf msvcrt.dll
import fscanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll

segment data use32 class=data
    nume_fisier db "input.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    numar dd 0
    format_hex db "%x", 0
    format_dec db "%d", 0ah
    space equ ' '
    format_afisare db "%x -> %d", 0ah
    
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
        
        mov esi, 0
        cld
        repeta:
        
            ; citire numar
            push dword numar
            push dword format_hex
            push dword [descriptor_fisier]
            call [fscanf]
            add esp, 3*4
    
            ; verificam citire
            cmp eax, -1
            je final
            
            mov eax, [numar]
            
            cmp eax, space
            je repeta
            
            ; luam bitii de 1 din numar
            mov ebx, [numar]
            mov eax, 0
            mov ecx, 32
            numara_bitii:
                shl ebx, 1
                adc eax, 0
            loop numara_bitii
            
            ; afisare numere in hexa si numarul de biti
            push dword eax
            push dword [numar]
            push dword format_afisare
            call [printf]
            add esp, 3*4
            
        jmp repeta
         
    final:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
    
    push dword 0
    call [exit]