; a * [ b + c + d / b ] + d 
bits 32

global start

extern exit
import exit msvcrt.dll

; a,b,c - byte, d - word
segment data use32 class=data
    a db 10
    b db 5
    c db 15
    d dw 25

; a * [ b + c + d / b ] + d 
segment code use32 class=code
    start:
        
        ; d / b
        mov AX, [d]     ; AX = d = 25
        mov BL, [b]     ; BL = b = 5
        div BL              ; AX = AX / BL = d / b = 5
        
        ; b + c + d / b
        add AL, [b]     ; AL = 5 + b = 10
        add AL, [c]     ; AL = 10 + c = 25
        
        ; a *  [ b + c + d / b ] 
        mov BL, [a]     ; BL = a = 10
        mul BL             ; AX = AX * BL = 25 * 10 = 250
        
        add AX, [d]      ; AX = 250 + 25 = 275
        
        push dword 0
        call [exit]