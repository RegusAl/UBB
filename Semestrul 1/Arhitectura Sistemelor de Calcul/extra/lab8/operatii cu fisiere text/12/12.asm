; Se da un nume de fisier (definit in segmentul de date). Sa se creeze un fisier cu numele dat, apoi sa se citeasca de la tastatura numere si sa se scrie valorile citite in fisier pana cand se citeste de la tastatura valoarea 0. 
bits 32
global start

extern exit, fopen, fprintf, fclose, printf, scanf
import exit msvcrt.dll
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    nume_fisier db "fisier.txt", 0
    mod_acces db "w", 0
    descriptor_fisier dd -1
    caracter dd 0
    format_dec db "%d", 0
    format_char db "%c", 0
    mesaj db "Dati numerele: ", 0

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
        
        ; mesaj
        push dword mesaj
        call [printf]
        add esp, 1*4
        
        ; citire caractere pe rand pana la caracterul '0'
        repeta:
            
            push dword caracter
            push dword format_char
            call [scanf]
            add esp, 2*4
            
            mov al, [caracter]
            cmp al, '0'
            je peste
            
            push dword caracter
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 2*4
        
        jmp repeta
        
        peste:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
        
    final:
    
    push dword 0
    call [exit]