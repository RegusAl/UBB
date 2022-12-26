;  Sa se citeasca de la tastatura un nume de fisier si un text. Sa se creeze un fisier cu numele dat in directorul curent si sa se scrie textul in acel fisier. Observatii: Numele de fisier este de maxim 30 de caractere. Textul este de maxim 120 de caractere. 
bits 32
global start

extern exit, printf, fopen, fclose, fprintf, scanf, gets
import exit msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import scanf msvcrt.dll
import gets msvcrt.dll

segment data use32 class=data
    nume_fisier resb 30
    mod_acces db "w", 0
    descriptor_fisier dd -1
    len equ 130
    text times len db "", 0
    mesaj_fisier db "Dati numele fisierului: ", 0
    mesaj_text db "Text: ", 0
    format_scriere db "%s", 0
    
segment code use32 class=code
    start:
    
        ; mesaj fisier
        push dword mesaj_fisier
        call [printf]
        add esp, 1*4
        
        ; citire nume fisier
        push dword nume_fisier
        call [gets]
        add esp, 1*4

        ; mesaj text
        push dword mesaj_text
        call [printf]
        add esp, 1*4
        
        ; citire text
        push dword text
        call [gets]
        add esp, 1*4
        
        ; fisier
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        ; verificare fisier
        mov [descriptor_fisier], eax
        cmp eax, 0
        je final
        
        ; punere text in fisier
        push dword text
        push dword [descriptor_fisier]
        call [fprintf]
        add esp, 2*4
        
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
        
    final:
    
    push dword 0
    call [exit]
