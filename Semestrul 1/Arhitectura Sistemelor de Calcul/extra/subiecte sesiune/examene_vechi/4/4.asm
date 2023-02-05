bits 32

global start

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    A dw 1000
    B db 6
    format_afisare db "Catul = %d, Restul = %d", 0

segment code use32 class=code
    start:
    
    mov ax, [A]
    div byte [B]
    mov ebx, 0
    mov edx, 0
    mov bl, al
    mov dl, ah
    
    push dword edx
    push dword ebx
    push dword format_afisare
    call [printf]
    add esp, 3*4
    
    
    push dword 0
    call [exit]