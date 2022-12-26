; Sa se citeasca de la tastatura doua numere a si b (in baza 10) şi să se determine relaţia de ordine dintre ele (a < b, a = b sau a > b). Afisati rezultatul în următorul format: "<a> < <b>, <a> = <b> sau <a> > <b>"
bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    a dd 0
    b dd 0
    mesaj_a db "a = ", 0
    mesaj_b db "b = ", 0
    format_dec db "%d", 0
    afisare_mare db "%d > %d", 0
    afisare_egal db "%d = %d", 0
    afisare_mic db "%d < %d", 0
    
segment code use32 class=code
    start:
        
        ; a = 
        push dword mesaj_a
        call [printf]
        add esp, 1*4
        
        ; citim a
        push dword a
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; b = 
        push dword mesaj_b
        call [printf]
        add esp, 1*4
        
        ; citim b
        push dword b
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        mov eax, [a]
        mov ebx, [b]
        
        ; comparam a cu b
        cmp eax, ebx
        jg mai_mare
        je egal
        jl mai_mic
        
        ; a > b
        mai_mare:
            push ebx
            push eax
            push dword afisare_mare
            call [printf]
            add esp, 3*4
            jmp peste
        
        ; a = b
        egal:
            push ebx
            push eax
            push dword afisare_egal
            call [printf]
            add esp, 3*4
            jmp peste

        ; a < b
        mai_mic:
            push ebx
            push eax
            push dword afisare_mic
            call [printf]
            add esp, 3*4
            
        peste:
        
    push dword 0
    call [exit]