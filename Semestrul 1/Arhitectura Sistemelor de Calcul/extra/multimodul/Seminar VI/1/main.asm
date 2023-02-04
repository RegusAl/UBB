; x = a + b
; parametri transmisi folosind registri
bits 32
global start

extern exit
import exit msvcrt.dll

extern addition


segment data use32 class=data
    a db 2
    b db 3
    x db 0

segment code use32 class=code
    start:
    
        mov bl, [a]
        mov bh, [b]
        
        call addition
        
        mov [x], al
        
    
    push dword 0
    call [exit]