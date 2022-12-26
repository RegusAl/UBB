; Sa se citeasca de la tastatura doua numere a si b de tip word. Sa se afiseze in baza 16 numarul c de tip dword pentru care partea low este suma celor doua numere, iar partea high este diferenta celor doua numere. 
; Exemplu:
;   a = 574, b = 136
;   c = 01B602C6h
bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    a dd 0
    b dd 0
    c dd 0
    mesaj_a db "a = ", 0
    mesaj_b db "b = ", 0
    format_dec db "%d", 0
    afisare_hex db "c = %xh", 0

segment code use32 class=code
    start:
    
        ; a = 
        push dword mesaj_a
        call [printf]
        add esp, 1*4
        
        ; citire a
        push dword a
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; b = 
        push dword mesaj_b
        call [printf]
        add esp, 1*4
        
        ; citire b
        push dword b
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; suma - partea inferioara
        mov ax, [a]
        add ax, [b]
        mov [c], ax
        
        ; diferenta - partea superioara
        mov ax, [a]
        sub ax, [b]
        mov [c+2], ax

        ; afisare
        push dword [c]
        push dword afisare_hex
        call [printf]
        add esp, 2*4
    
    push dword 0
    call [exit]