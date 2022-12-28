; Se dau un nume de fisier si un text (definite in segmentul de date). Textul contine litere mici, litere mari, cifre si caractere speciale. Sa se inlocuiasca toate CIFRELE din textul dat cu caracterul 'C'. Sa se creeze un fisier cu numele dat si sa se scrie textul obtinut prin inlocuire in fisier. 
bits 32
global start

extern exit, fopen, fprintf, fclose
import exit msvcrt.dll
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll

segment data use32 class=data
    nume_fisier db "fisier.txt", 0
    mod_acces db "w", 0
    descriptor_fisier dd -1
    text db "Ana are 34 mere. Ionut are 456 pere si 12 castane.", 0
    len equ ($-text)
    format_char db "%c", 0
    caracter dd "C", 0
    
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
        
        mov ecx, len
        mov esi, 0
        repeta:
            push ecx
        
            cmp byte [text+esi], '0'
            jl peste
            cmp byte [text+esi], '9'
            jg peste
            
            push dword caracter
            ;push dword format_char
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 2*4
            
            jmp gata
            
            peste:
           
            push dword [text+esi]
            push dword format_char
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 3*4

            gata:
            inc(esi)
            pop ecx
        
        loop repeta
        
        
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
    
    final:
    
    push dword 0
    call [exit]