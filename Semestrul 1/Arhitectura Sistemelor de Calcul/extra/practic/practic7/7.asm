; Se citesc numere de la tastatura pana la citirea numarului 0.
; Sa se scrie intr-un fisier toate numerele (in decimal si in hexa) care au suma cifrelor egala cu o constanta k definita in segmentul de date
bits 32

global start

extern exit, fopen, fclose, fprintf, scanf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    nume_fisier db "fisier.txt", 0
    mod_acces db "w", 0
    descriptor_fisier dd -1
    format_dec db "%d", 0
    format_afisare db "%d, %x", 13, 10, 0
    k dd 5
    sir times 50 dd 0
    numar dd 0
    suma dd 0
    contor dd 0

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

        ; citire numere de la tastatura
        mov esi, 0
        citire:
            
            ; citim numerele
            push dword numar
            push dword format_dec
            call [scanf]
            add esp, 2*4
            
            ; verificam daca am inserat 0, pentru a iesi din program
            cmp dword [numar], 0
            je final
            
            ; calculam suma luand pe rand cifra unitatilor 
            mov eax, [numar]
            mov dword [contor], 0
            mov dword [suma], 0
            mov ebx, 10
            cifre:
            
                cmp eax, 0
                je gata
                
                mov edx, 0
                div ebx          ; edx = edx:eax % 10
                add [suma], edx
                add dword [contor], 1
            
            jmp cifre
            
            gata:
            
            ; comparam suma cifrelor cu k
            mov eax, [k]
            cmp [suma], eax
            jne alt_numar
            
            ; punem in sir numerele ce au suma cifrelor egale cu k
            mov ecx, [contor]
            mov eax, [numar]
            mov [sir+esi], eax
            add esi, 4
            
            ; afisare sir de numere in fisier
            push dword [numar]
            push dword [numar]
            push dword format_afisare
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 4*4

        alt_numar:
        
        jmp citire
        
        final:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
    
    
    push dword 0
    call [exit]