; x = a + b
; parametri transmisi prin variabile globale
bits 32

global start

extern exit
import exit msvcrt.dll

extern addition

global a
global b
global x

segment data use32 class=data
    a db 2
    b db 3
    x db 0

segment code use32 class=code
    start:
    
        call addition
    
    push dword 0
    call [exit]