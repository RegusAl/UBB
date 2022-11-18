bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data

; ZF (Zero Flag)
segment code use32 class=code
    start:
    ; --------------------------------------    
    ; Zero Flag (ZF) indicates zero result:
    ; - if the result is zero, ZF=1
    ; - otherwise, ZF=0
        
        mov eax, 1
        and eax, eax    ; clear the ZF (ZF = 0)
        
        mov al, 0fh
        add al, 0f1h    ; set the ZF (ZF = 1)
        
        mov eax, 1
        or eax, eax     ; clear the ZF
        
        mov ax, 0ffffh
        inc ax          ; set the ZF
        
        mov eax, 1
        and eax, eax    ; clear the ZF
        
        mov ax, 1
        dec ax          ; set the ZF
    
        ; exit(0)
        push dword 0    ; push the parameter for exit onto the stack
        call [exit]     ; call exit to terminate the program
