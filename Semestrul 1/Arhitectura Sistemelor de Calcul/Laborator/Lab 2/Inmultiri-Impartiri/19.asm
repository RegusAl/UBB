bits 32

global start

extern exit
import exit msvcrt.dll

; a,b,c,d-byte, e,f,g,h-word
segment data use32 class=data
    a db 10
    b db 20
    c db 30
    d db 55
    e dw 1234h
    f dw 5555h
    g dw 6789h
    h dw 1000h


; (e + g) * 2 / (a * c) + (h – f) + b * 3 
segment code use32 class=code
    start:
        
        ; e + g
        mov ax, [e]
        add ax, [g]
        
        ; ( ) * 2
        mov bx, 2
        mul bx                ; EAX = AX * BX
        
        push dx
        push ax
        
        ; (a * c)
        mov al, [a]
        mov cl, [c]
        mul cl                  ; AX = AL * CL
        
        ; (e + g) * 2 / (a * c) 
        mov bx, ax
        pop ax
        pop dx
        div bx                   ; AX = DX:AX / BX      DX = DX:AX % BX

        ; (h - f)
        mov dx, [h]
        sub dx, [f]
        
        add ax, dx
        mov cx, ax
        mov al, [b]
        mul bl                    ; AX = AL * BL
        add cx, ax
        
        ; rezultatul este in CX
        

     push dword 0
     call [exit]