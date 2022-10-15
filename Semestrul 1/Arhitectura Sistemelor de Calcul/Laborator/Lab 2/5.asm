; (a*d+e)/[c+h/(c-b)] 
bits 32

global start

extern exit
import exit msvcrt.dll

; a,b,c,d-byte, e,f,g,h-word
segment data use32 class=data
    a db 5
    b db 3
    c db 10
    d db 6
    e dw 30
    f dw 30
    g dw 100
    h dw 14
    
 ; (a*d+e)/[c+h/(c-b)]  
segment code use32 class=code
    start:
        
        ; a * d
        mov AX, [a]     ; AX = a = 5
        mov BL, [d]     ; BL = d = 6
        mul BL             ; AX = AX * BL = 5 * 6 = 30
        
        ; (a * d) + e
        add AX, [e]      ; AX = AX + e = 30 + 30 = 60
        
        mov BX, AX    ; BX = AX = 60 
        
        ; c - b
        mov CL, [c]     ; CL = 10
        sub CL, [b]      ; CL = c - b = 10 - 3 = 7
        
        ; h / (c - b)
        mov AX, [h]     ; AX = h = 14
        div CL              ; AX = AX / CL = 14 / 7 = 2
        
        ; c + h / (c - b)
        add AL, [c]      ; AX = AX + c = 2 + 10 = 12
        
        mov CL, AL     ; CL = AL = 12
        mov AX, BX     ; AX = BX = 60
        
        ; (a*d+e)/[c+h/(c-b)]  
        div CL               ; AX = AX / CL = 60 / 12 = 5
        
        push dword 0
        call [exit]