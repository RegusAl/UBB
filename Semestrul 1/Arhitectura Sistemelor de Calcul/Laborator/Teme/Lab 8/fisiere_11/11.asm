; Se da un nume de fisier (definit in segmentul de date). Sa se creeze un fisier cu numele dat, apoi sa se citeasca de la tastatura cuvinte si sa se scrie in fisier cuvintele citite pana cand se citeste de la tastatura caracterul '$'. 
bits 32
global start

extern exit, fopen, fprintf, fclose, gets, printf, scanf
import exit msvcrt.dll
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll
import gets msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data

    nume_fisier db "tema.txt", 0
    mod_acces db "w", 0
    caracter db 0, 0
    format db "%c", 0
    mesaj db "Introduceti cuvinte: ", 0
    descriptor_fisier dd -1
    
    mesaj_eroare db "Eroare la deschiderea fisierului"
    
segment code use32 class=code
    start:
    
        ; apelam fopen pentru a crea fisierul
        ; functia returnaza in EAX descriptorul fisierului sau 0 in caz de eroare
        ; eax = fopen(nume_fisier, mod_acces)
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        mov [descriptor_fisier], eax
        
        cmp eax, 0
        je eroare
        
        push dword mesaj
        call [printf]
        add esp, 1*4
        
        ; citim cate un caracter pana dam de "$"
        citire:
        
            pushad 
            push dword caracter
            push dword format
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
            add esp, 4 * 2
            popad
        
        jmp citire
        
        peste:
        
        ; fclose(descriptor_fisier)
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
        
        jmp final
        eroare: 
        push dword [mesaj_eroare]
        call [printf]
        add esp, 1*4
        
    final:
    push dword 0
    call [exit]