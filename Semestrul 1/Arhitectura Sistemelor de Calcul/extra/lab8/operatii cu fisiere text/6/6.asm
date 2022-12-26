; Se da un fisier text. Sa se citeasca continutul fisierului, sa se determine cifra cu cea mai mare frecventa si sa se afiseze acea cifra impreuna cu frecventa acesteia. Numele fisierului text este definit in segmentul de date. 
bits 32
global start

extern exit, fopen, fread, scanf, printf, fclose
import exit msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll
import fclose msvcrt.dll

segment data use32 class=data
    nume_fisier db "fisier.txt", 0
    descriptor_fisier dd -1
    mod_acces db "r", 0
    format_afisare db "Cifra %c are frecventa %d", 0
    caractere_citite dd 0
    cifra dd 0
    contor dd 0
    sir_cifre equ 10
    frecvente resb sir_cifre
    len equ 100
    text times len db 0
    

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
        
            ; citire fisier
            push dword [descriptor_fisier]
            push dword len
            push dword 1
            push dword text
            call [fread]
            add esp, 4*4
            
            cmp eax, 0
            je inchidere_fisier
            
            mov [caractere_citite], eax

            ; parcurgerea caracterelor
            mov esi, text
            
            verificare: 
            
                lodsb
                
                cmp al, 0
                je done
                
                cmp al, '0'
                jl verificare
                
                cmp al, '9'
                jg verificare
                
                mov edx, 1
                add [frecvente + eax - '0'], edx
                cmp [frecvente + eax - '0'], bl
                jl next
                mov ebx, [frecvente + eax - '0']
                mov [cifra], eax
                mov [contor], bl
                
                next:
                    jmp verificare
                    
                done:
                    push edi
                    mov edi, text
                    xor eax, eax
                    mov ecx, len
                    rep stosd
                    pop edi
                
        jmp repeta
        
        inchidere_fisier:
        
            ; inchidem fisierul
            push dword [descriptor_fisier]
            call [fclose]
            add esp, 1*4
        
        afisare:
        ; afisam cifra si frecventa corespunzatoare
        push dword [contor]
        push dword [cifra]
        push dword format_afisare
        call [printf]
        add esp, 3 * 4
    
    final:
    
    push dword 0
    call [exit]