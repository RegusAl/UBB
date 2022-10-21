bits 32
global start

extern exit
import exit msvcrt.dll

; Scrieți un program în limbaj de asamblare care să rezolve expresia aritmetică,
; considerând domeniile de definiție ale variabilelor
; a - doubleword; b, d - byte; c - word; e - qword
segment data use32 class=data
    a dd 125
	b db 2
	c dw 15
	d db 200
	e dq 80
    
    x dq 0

; a + b/c - d*2 - e
segment code use32 class=code
    start:
        ; b/c
        mov al, [b]             ; AL = b
        mov ah, 0               ; AX = b (am extins b pe 16 biti fara semn)
        mov dx, 0               ; DX:AX = b (am extins b pe 32 biti fara semn)
        div word [c]            ; AX = DX:AX/c = b/c si DX = DX:AX%c
        
        ; mutam rezultatul in BX
        mov bx, ax              ; BX = b/c
        
        ; d*2
        mov al, 2
        mul byte [d]            ; AX = AL*d = 2*d
        
        ; b/c - d*2
        sub bx, ax              ; BX = b/c - d*2
        mov cx, 0               ; CX:BX = b/c - d*2
        
        ; a + b/c - d*2
        mov ax, word [a]
        mov dx, word [a+2]      ; DX:AX = a
        add ax, bx
        adc dx, cx              ; DX:AX = a + b/c - d*2 + CF
        
        ; mutam rezultatul in EAX
        push dx
        push ax
        pop eax                 ; EAX = a + b/c - d*2
        
        ; a + b/c - d*2 - e
        mov edx, 0              ; EDX:EAX = a + b/c - d*2
        sub eax, dword [e]
        sbb edx, dword [e+4]    ; EDX:EAX = a + b/c - d*2 - e - CF
        
        mov [x], eax
        mov [x+4], edx
    
        ; exit(0)
        push dword 0            ; push the parameter for exit onto the stack
        call [exit]             ; call exit to terminate the program
