; 2-(c+d)+(a+b-c) 
bits 32

global start

extern exit
import exit msvcrt.dll

; a, b, c, d - byte
segment data use32 class=data
    a db 5
    b db 7
    c db 15
    d db 20

segment code use32 class=code
    start:
    
        ; 2 - (c + d)
        mov AL, 2       ; AL = 2
        mov AH, [c]    ; AH = c = 15
        add AH, [d]     ; AH = c + d = 35
        sub AL, AH     ; AL = AL - AH = 2 - 35 = -33
        
        ; a + b - c
        mov AH, [a]     ; AH = a = 5
        add AH, [b]      ; AH = a + b = 5 + 7 = 12
        sub AH, [c]      ; AH = a + b - c = 12 - 15 = -3
        
        ; 2 - (c + d) + (a + b - c)
        add AL, AH      ; -33 + (-3) = -36
        
        push dword 0
        call [exit]