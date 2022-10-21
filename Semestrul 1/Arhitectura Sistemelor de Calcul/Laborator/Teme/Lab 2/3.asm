; d-(a+b)-(c+c) 
bits 32

global start

extern exit
import exit msvcrt.dll

; a, b, c, d - word
segment data use32 class=data
    a dw 10
    b dw 13
    c dw 7
    d dw 40

; d-(a+b)-(c+c) 
segment code use32 class=code
    start:
        
        ; a + b
        mov AX, [a]     ; AX = a = 10
        add AX, [b]      ; AX = a + b = 10 + 13 = 23
        
        ; d - (a + b)
        mov BX, [d]     ;BX = d = 40
        sub BX, AX    ; BX = d - (a + b) = 40 - 23 = 17
        
        ; c + c
        mov AX, [c]     ; AX = c = 7
        add AX, [c]      ; AX = c + c = 14
        
        ; d-(a+b)-(c+c) 
        sub BX, AX     ; BX = 17 - 14 = 3
        mov AX, BX    ; AX = 3
        
        push dword 0
        call [exit]