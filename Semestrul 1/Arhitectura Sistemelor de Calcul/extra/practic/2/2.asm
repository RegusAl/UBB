; Se citește de la tastatură un număr N și apoi N numere.
; Să se calculeze suma numerelor pare introduse, să se calculeze suma numerelor impare introduse, apoi diferența dintre cele două sume.
; Să se afișeze în fișierul output.txt cele 3 rezultate, în baza 16, pe linii separate.
bits 32

global start

extern exit, fopen, fclose, scanf, fprintf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll

segment data use32 class=data
    nume_fisier db "output.txt", 0
    mod_acces db "w", 0
    descriptor_fisier dd -1
    numar dd 0
    format_dec db "%d", 0
    format_hex db "Diferenta: %x", 0
    doi dd 2
    suma_pare dd 0
    suma_impare dd 0
    format_afisare db "Suma numere pare: %x, Suma numere impare: %x", 0ah
    

segment code use32 class=code
    start:
    
        ; citire numar N
        push dword numar
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        mov ecx, [numar]
        citire_numere:
        
            push ecx
            
            push dword numar
            push dword format_dec
            call [scanf]
            add esp, 2*4
            
            mov eax, [numar]
            mov edx, 0
            
            div dword [doi]      ; edx = edx:eax % 2
            mov eax, [numar]
            cmp edx, 0
            je par
            
                add [suma_impare], eax 
                jmp peste
            
            par:
            
                add [suma_pare], eax 
            
            peste:
            
            pop ecx
                
        loop citire_numere
        
        ; deschidere fisier
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        
        ; verificare fisier
        cmp eax, 0
        je final
        mov [descriptor_fisier], eax

        push dword [suma_impare]
        push dword [suma_pare]
        push dword format_afisare
        push dword [descriptor_fisier]
        call [fprintf]
        add esp, 4*4
        
        mov eax, [suma_pare]
        sub eax, [suma_impare]
        
        push dword eax
        push dword format_hex
        push dword [descriptor_fisier]
        call [fprintf]
        add esp, 3*4
        
        final:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
    
    push dword 0
    call [exit]

