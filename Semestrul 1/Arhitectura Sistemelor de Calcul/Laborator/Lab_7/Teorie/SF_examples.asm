bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data

; SF (Sign Flag)
segment code use32 class=code
    start:
    ; ------------------------------------------------------------
    ; Sign flag (SF) indicates the sign of the result:
    ; - useful only when dealing with signed numbers
    ; - is simply a copy of the most significant bit of the result
    
        mov eax, -1
        and eax, eax    ; clear the ZF (ZF=0), set the SF (SF=1)
    
        mov al, 15
        add al, 97      ; 15 + 97 = 112 --> clear the SF (SF=0)
        
        mov al, 15
        sub al, 97      ; 15 - 97 = -82 --> set the SF (SF=1)
    
        ; exit(0)
        push dword 0    ; push the parameter for exit onto the stack
        call [exit]     ; call exit to terminate the program
