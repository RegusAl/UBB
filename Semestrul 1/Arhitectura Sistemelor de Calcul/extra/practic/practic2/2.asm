bits 32
global start

extern exit, scanf, fprintf, fopen, fclose
import exit msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll

segment data use32 class=data
    nume_fisier db "fisier.txt", 0
    mod_acces db "w", 0
    descriptor_fisier dd -1
    numar dd 0
    numar_biti dd 0
    egal db " = ", 0
    format_dec db "%d (dec)", 0
    format_hex db "%x (hexa)", 0
    format_numar_biti db "numarul de biti 1 este %d", 0ah

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
        
        ; citim numere pana cand dam de '0'
        repeta:
            
            ; citire
            push dword numar
            push dword format_dec
            call [scanf]
            add esp, 2*4
            
            cmp dword [numar], 0
            je peste
            
            ; numar (dec) in fisier
            push dword [numar]
            push dword format_dec
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 3*4
            
            ; egal
            push dword egal
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 2*4
            
            ; numar (hexa) in fisier
            push dword [numar]
            push dword format_hex
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 3*4
            
            mov ecx, 32
            ; ebx = numarul de biti de 1 din numar
            xor ebx, ebx
            mov eax, [numar]
            numaram_biti:
                shr eax, 1
                adc ebx, 0
            loop numaram_biti
            mov [numar_biti], ebx
            
            ; egal
            push dword egal
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 2*4
            
            ; numar de biti de 1 in fisier
            push dword [numar_biti]
            push dword format_numar_biti
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 3*4
        
        jmp repeta
        
        peste:
        
        final:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
    
    push dword 0
    call [exit]
