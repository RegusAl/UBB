; Se citeste de la tastatura m,n apoi m numere zecimale, pe linii diferite. Sa se afiseze nr cu cel putin n cifre pare in output.txt.
bits 32

global start

extern exit, printf, scanf, fprintf, fopen, fclose
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll

segment data use32 class=data
    nume_fisier db "output.txt", 0
    mod_acces db "w", 0
    descriptor_fisier dd -1
    m dd 0
    n dd 0
    numar dd 0
    format_dec db "%d", 0
    afisare_m db "M = ", 0
    afisare_n db "N = ", 0
    afisare_numar db "numar: ", 0
    zece dd 10
    doi dd 2
    afisare_numere db "%d ", 0

segment code use32 class=code
    start:
    
        ; citire m
        push dword afisare_m
        call [printf]
        add esp, 1*4
        
        push dword m
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; citire n
        push dword afisare_n
        call [printf]
        add esp, 1*4
        
        push dword n
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; deschidere fisier
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        ; verificare fisier
        cmp eax, 0
        je final
        mov [descriptor_fisier], eax
        
        mov ecx, [m]
        repeta:
        
            push ecx
        
            ; citire numar
            push dword afisare_numar
            call [printf]
            add esp, 1*4
            
            push dword numar
            push dword format_dec
            call [scanf]
            add esp, 2*4
            
            ; aflam numarul de cifre pare
            mov eax, [numar]
            mov edx, 0
            mov ebx, 0
            numara:
            
                cmp eax, 0
                je gata
                
                mov edx, 0
                div dword [zece]  ; edx = edx:eax % 10
                mov ecx, eax
                mov eax, edx
                mov edx, 0
                div dword [doi]   ; edx = edx:eax % 2
                cmp edx, 0
                jne impar
                
                inc(ebx)
                
                impar:
                
                mov eax, ecx
            
            jmp numara
            
            gata:
            
            cmp ebx, [n]
            jl nu_se_afiseaza
            
            ; afisare numar
            push dword [numar]
            push dword afisare_numere
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 3*4
            
            nu_se_afiseaza:
                pop ecx
        
        loop repeta
    
        final:
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
        
    push dword 0
    call [exit]