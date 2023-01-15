; Se citeste un sir din input.txt. sa se afiseze invers.
bits 32

global start

extern exit, fopen, fclose, printf, fscanf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fscanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    nume_fisier db "input.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    len equ 100
    sir times 100 db 0
    sir_inversat times 100 db 0
    format_char db "%c", 0
    chr db -1
   
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
        
        mov edi, sir
        mov ebx, 0
        repeta:

            ; citire caracter
            push dword chr
            push dword format_char
            push dword [descriptor_fisier]
            call [fscanf]
            add esp, 3*4
            
            cmp eax, -1
            je gata
            
            mov al, [chr]
            stosb
            inc(ebx)
        
        jmp repeta
        
        gata:
        
        ; inversam sirul
        mov ecx, ebx
        dec(ebx)
        mov esi, 0
        inversare:
            
            mov al, [sir+ebx]
            mov [sir_inversat+esi], al
            dec(ebx)
            inc(esi)
        
        loop inversare
    
        final:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
        
        ; afisare fisier
        push dword sir_inversat
        call [printf]
        add esp, 1*4
        
        
    push dword 0
    call [exit]