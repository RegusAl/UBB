; Se dau un nume de fisier si un text (definite in segmentul de date). Textul contine litere mici si spatii. Sa se inlocuiasca toate literele de pe pozitii pare cu numarul pozitiei. Sa se creeze un fisier cu numele dat si sa se scrie textul obtinut in fisier. 
bits 32
global start

extern exit, fopen, fprintf, fclose, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    nume_fisier db "fisier.txt", 0
    mod_acces db "w", 0
    descriptor_fisier dd -1
    text db "Ana are mere si pere", 0
    len equ $-text
    format_char db "%c", 0
    format_dec db "%d", 0
    poz db 0
   
segment code use32 class=code
    start:
    
        ; deschidere fisier
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        ; verificare
        mov [descriptor_fisier], eax
        cmp eax, 0
        je final
        
        mov esi, 0
        cld
        mov ecx, len/2
        jecxz final
        
        repeta:
            push ecx
            
            push dword esi
            push dword format_dec
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 3*4
            
            inc(esi)
            
            push dword [text+esi]
            push dword format_char
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 3*4
            
            inc(esi)
            
            pop ecx
            
        loop repeta
        
        mov ebx, 1
        test ebx, len
        jz final
        
        push dword esi
        push dword format_dec
        push dword [descriptor_fisier]
        call [fprintf]
        add esp, 3*4
       
    final:
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
        
    push dword 0
    call [exit]