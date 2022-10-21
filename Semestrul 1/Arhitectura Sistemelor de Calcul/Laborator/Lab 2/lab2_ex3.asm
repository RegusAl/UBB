bits 32

global start

extern exit
import exit msvcrt.dll

; Scrieți un program în limbaj de asamblare care să rezolve expresia aritmetică,
; considerând domeniile de definiție ale variabilelor
; a - byte, b - word
segment data use32 class=data
    a db 10
    b dw 40

; (b / a * 2 + 10) * b - b * 15
segment code use32 class=code
    start:
        ; b/a
        mov ax, [b]         ; AX = b
        div byte [a]        ; AL = AX/a = b/a si AH = AX%a
        
        ; b/a * 2
        mov ah, 2           ; AH = 2
        mul ah              ; AX = AL*AH = b/a * 2
        
        ; b/a * 2 + 10
        add ax, 10          ; AX = b/a * 2 + 10
        
        ; (b / a * 2 + 10) * b
        mul word [b]        ; DX:AX = AX*b = (b / a * 2 + 10) * b
        
        ; mutam rezultatul partial in EBX folosind stiva
        push dx
        push ax
        pop ebx             ; EBX = (b / a * 2 + 10) * b
        
        ; b*15
        mov ax, [b]         ; AX = b
        mov dx, 15          ; DX = 15
        mul dx              ; DX:AX = b*15
        
        ; mutam rezultatul partial in EAX folosind stiva
        push dx
        push ax
        pop eax             ; EAX = b*15
        
        sub ebx, eax        ; EBX = (b / a * 2 + 10) * b - b * 15
    
        ; exit(0)
        push dword 0        ; push the parameter for exit onto the stack
        call [exit]         ; call exit to terminate the program
