; c+(a*a-b+7)/(2+a), a-byte; b-doubleword; c-qword
; interpretare cu semn
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    a db 5
    b dd 10
    c dq -100

segment code use32 class=code
    start:
     
        ; (a*a-b+7)
        mov al, [a]
        mul al           ; ax = a * a
        sub ax, [b]
        add ax, 7
        
        ; (2 + a)
        mov bl, [a]
        add bl, 2
        
        idiv bl         ; al = ax / bl, ah = ax % bl
        cbw
        cwde
        cdq             ; al --> ax --> eax --> edx : eax
        
        add eax, [c]
        adc edx, [c+4]            ; rezultatul este in edx : eax
        
    push dword 0
    call [exit]