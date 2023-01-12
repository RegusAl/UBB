; Se dă un șir de 10 numere în baza 16 în fișierul input.txt. 
; Să se determine cifra minimă din fiecare număr.
; Să se afișeze acest șir al cifrelor minime, în baza 10, pe ecran.

bits 32

global start

extern exit, fopen, fclose, fscanf, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fscanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    nume_fisier db "input.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    numar dd 0
    format_dec db "%d  ", 0
    zece dd 10
    spatiu dd ' ', 0
    

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
        
        ; citire numere din fisier
        mov ecx, 10
        citire:
            
            push ecx
            
            ; citire numar
            push dword numar
            push dword format_dec
            push dword [descriptor_fisier]
            call [fscanf]
            add esp, 3*4
            
            ; luam cate o cifra ci vedem daca este minim
            mov ebx, 9
            mov eax, [numar]
            repetare_cifre:
                
                cmp eax, 0
                je gata
                
                mov edx, 0
                div dword [zece]
                
                cmp edx, ebx
                jg nu_minim
                
                mov ebx, edx
                
                nu_minim:
            
            jmp repetare_cifre
            
            gata:
            ; afisare cifra minima din numar
            push dword ebx
            push dword format_dec
            call [printf]
            add esp, 2*4
            
            pop ecx
        
        loop citire
        
    final:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4

    push dword 0
    call [exit]