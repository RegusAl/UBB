bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    a dd 25
    b dq 100

; a + b (DWORD + QWORD)
segment code use32 class=code
    start:
        ;     EDX                                 EAX
        ; a =                                     xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
        ; b = xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
        
        ; fara semn
        mov eax, [a]
        mov edx, 0      ; EDX:EAX = a (conversie fara semn)
        add eax, [b]
        adc edx, [b+4]  ; EDX:EAX = a+b
        
        ; cu semn
        mov eax, [a]
        cdq             ; EDX:EAX = a (conversie cu semn)
        add eax, [b]
        adc edx, [b+4]  ; EDX:EAX = a+b
    
        ; exit(0)
        push dword 0    ; push the parameter for exit onto the stack
        call [exit]     ; call exit to terminate the program
