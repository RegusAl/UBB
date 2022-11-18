bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data

segment code use32 class=code
    start:
    ; ---------------------------------------------------------------------------------------------
    ; INTEGER OVERFLOW
    
    ; ---------------------------------------------------------------------------------------------
    ; 1. Multiplication
    ; MUL si IMUL set CF=1 and OF=1 if the high octet/word of result is different from 0

        ; no overflow
        mov al, 5
        mov bl, 51          ; 5 * 51 = 255
        mul bl              ; no overflow
        
        ; byte multiply overflow
        mov al, 5
        mov bl, 170         ; 5 * 170 = 850 (AX = 11 01010010)
        mul bl              ; multiply overflow - high octet in AX is different from 0 --> CF=1 OF=1
        
        ; word multiply overflow
        mov ax, 32768
        mov bx, 2           ; 32768 * 2 = 65536 (1 0000000000000000)
        mul bx              ; multiply overflow - high octet in EAX is different from 0 --> CF=1 OF=1
    
    ; ---------------------------------------------------------------------------------------------
    ; 2. Division
    ; DIV and IDIV generate DIVIDE OVERFLOW if the quotient/remainder is larger than register size
        
        ; no overflow
        mov ax, 510
        mov bl, 2           ; 510 : 2 = 255 --> the quotient will fit in the AL
        div bl              ; no overflow
    
        ; byte divide overflow
        mov ax, 512
        mov bl, 2           ; 512 : 2 = 256 --> the quotient won't fit in the AL
        div bl              ; divide overflow - maximum value represented on 8 bits is 255
        
        ; word divide overflow
        mov eax, 131072
        mov bx, 2           ; 131072 : 2 = 65536 --> the quotient won't fit in the AX
        div bx              ; divide overflow - maximum value represented on 16 bits is 65535
    
    ; ---------------------------------------------------------------------------------------------
    ; Pay attention on division operations:
    ; - DIV instruction performs the division operation for UNSIGNED integers.
    ; - IDIV instruction performs the division operation for SIGNED integers.
    
        ; unsigned division
        xor eax, eax
        mov ax, -1          ; AX = ffffh
        mov bl, 1
        div bl              ; AL = AX/BL = ffffh/1 = ffffh (65535) => divide overflow
        
        ; signed division
        xor eax, eax
        mov ax, -1          ; AX = ffffh
        mov bl, 1
        idiv bl             ; AL = AX/BL = (-1)/1 = -1 (ffh) => no overflow
    
        ; call exit(0)
        push dword 0        ; push the parameter for exit onto the stack
        call [exit]         ; call exit to terminate the program
