; Se da un nume de fisier (definit in segmentul de date). Sa se creeze un fisier cu numele dat, apoi sa se citeasca de la tastatura numere si sa se scrie din valorile citite in fisier numerele divizibile cu 7, pana cand se citeste de la tastatura valoarea 0. 
bits 32
global start

extern exit, fopen, fprintf, fclose, scanf
import exit msvcrt.dll
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    nume_fisier db "fisier.txt", 0
    mod_acces db "w", 0
    descriptor_fisier dd -1
    numar dd 0
    format_dec db "%d ", 0

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
    
        repeta:
            
            ; citire numar
            push dword numar
            push dword format_dec
            call [scanf]
            add esp, 2*4
            
            ; vedem daca numarul este 0
            cmp dword [numar], 0
            je gata
            
            mov ax, [numar]
            mov dx, [numar+2]
            mov bx, 7
            div bx              ; ax = dx:ax / 7, dx = dx:ax % 7
            
            cmp dx, 0
            jne nu_divizibil
            
            ; punem numarul in fisier daca este divizibil cu 7
            push dword [numar]
            push dword format_dec
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 3*4
            
            nu_divizibil:
            
        jmp repeta
        
        gata:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
    
    final:
    
    push dword 0
    call [exit]