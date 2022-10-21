bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    a dw 5
    b dd 25

; a + b (WORD + DWORD)
segment code use32 class=code
    start:
        ;     DX                AX
        ; a =                   xxxxxxxx xxxxxxxx
        ; b = xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
        
        ; fara semn
        mov ax, [a]
        mov dx, 0       ; DX:AX = a (conversie fara semn)
        add ax, [b]
        adc dx, [b+2]   ; DX:AX = a+b
        
        ; cu semn
        mov ax, [a]
        cwd             ; DX:AX = a (conversie cu semn)
        add ax, [b]
        adc ax, [b+2]   ; DX:AX = a+b
        
        ; exit(0)
        push dword 0    ; push the parameter for exit onto the stack
        call [exit]     ; call exit to terminate the program
