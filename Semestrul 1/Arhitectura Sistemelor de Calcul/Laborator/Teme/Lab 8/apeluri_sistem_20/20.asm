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
    message_a db "a = ", 0
    b dd 0
    message_b db "b = ", 0
    format db "%x", 0
    suma resd 1
    diferenta resd 1
    format_suma db "Suma partilor low este: %x    ", 0
    format_diferenta db "Diferenta partilor high este: %x", 0

segment code use32 class=code
    start:
    
    ; vom apela printf(message_a)
    push dword message_a
    call [printf]
    add esp, 1*4
    
    ; vom apela scanf(format, a)
    push dword a
    push dword format
    call [scanf]
    add esp, 2*4
    
    ; vom apela printf(message_b)
    push dword message_b
    call [printf]
    add esp, 1*4
    
    ; vom apela scanf(format, b)
    push dword b
    push dword format
    call [scanf]
    add esp, 2*4
    
    ; facem adunarea word-ului inferior
    mov ax, word [a]
    add ax, word [b]
    mov [suma], ax
    mov ax, 0
    
    PUSHAD
    
    ; afisam suma
    push dword [suma]
    push dword format_suma
    call [printf]
    add esp, 2*4
    
    POPAD
    
    ; facem scaderea word-ului superior
    mov ax, word [a+2]
    sub ax, word [b+2]
    mov [diferenta], ax
    
    PUSHAD
    
    ; afisam diferenta
    push dword [diferenta]
    push dword format_diferenta
    call [printf]
    add esp, 2*4
        
    POPAD
    
    push dword 0
    call [exit]