; Se da un nume de fisier (definit in segmentul de date). Sa se creeze un fisier cu numele dat, apoi sa se citeasca de la tastatura cuvinte si sa se scrie in fisier cuvintele citite pana cand se citeste de la tastatura caracterul '$'. 
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
    caracter db 0
    format_char db "%c", 0
    mesaj db "Dati textul: ", 0

segment code use32 class=code
    start:
    
        ; fopen
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
        
        ; se citeste cate un caracter pana la caracterul '$'
        repeta:
        
            pushad
            push dword caracter
            push dword format_char
            call [scanf]
            add esp, 2*4
            popad
            
            mov al, [caracter]
            
            cmp al, '$'
            je peste
            
            pushad
            push dword caracter
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 2*4
            popad
            
        jmp repeta
        
        peste:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
    
    final:
    
    push dword 0
    call [exit]