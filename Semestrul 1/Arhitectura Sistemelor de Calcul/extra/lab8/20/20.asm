; Sa se citeasca de la tastatura in baza 16 doua numere a si b de tip dword si sa se afiseze suma partilor low si diferenta partilor high. Exemplu:
; a = 00101A35h, b = 00023219h
; suma = 4C4Eh
; diferenta = Eh
bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    a dd 0
    b dd 0
    mesaj_a db "a (base16) = ", 0
    mesaj_b db "b (base16) = ", 0
    format_hex db "%x", 0
    afisare_suma db "Suma = %xh ", 0
    afisare_diferenta db "Diferenta = %xh", 0
    suma dd 0
    diferenta dd 0

segment code use32 class=code
    start:
    
        ; a = 
        push dword mesaj_a
        call [printf]
        add esp, 1*4
        
        ; citim a
        push dword a
        push dword format_hex
        call [scanf]
        add esp, 2*4
        
        ; b = 
        push dword mesaj_b
        call [printf]
        add esp, 1*4
        
        ; citim b
        push dword b
        push dword format_hex
        call [scanf]
        add esp, 2*4

        ; calculam suma partilor low
        mov ax, [a]
        add ax, [b]
        mov [suma], ax

        ; calculam diferenta partilor high
        mov ax, [a+2]
        sub ax, [b+2]
        mov [diferenta], ax
        
        ; afisare suma
        push dword [suma]
        push dword afisare_suma
        call [printf]
        add esp, 2*4

        ; afisare diferenta
        push dword [diferenta]
        push dword afisare_diferenta
        call [printf]
        add esp, 2*4
        
    push dword 0
    call [exit]