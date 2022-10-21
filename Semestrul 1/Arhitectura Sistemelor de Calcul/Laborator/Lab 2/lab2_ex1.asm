bits 32

global start        

extern exit
import exit msvcrt.dll

segment data use32 class=data
    ; a, b, c - byte
    a db 11h
    b db 33h
    c db 22h
    
    ; a, b, c - word
    ; a dw 11h
    ; b dw 33h
    ; c dw 22h
    
    ; a, b, c - dword
    ; a dd 11h
    ; b dd 33h
    ; c dd 22h

; Calculati expresia aritmetica: a + b - c.
segment code use32 class=code
    start:
        ; a, b, c - byte
        mov al, [a]
        add al, [b]         ; al = al + b = a + b
        sub al, [c]         ; al = al - c = a + b - c
        
        ; a, b, c - word
        ; mov ax, [a]
        ; add ax, [b]         ; ax = ax + b = a + b
        ; sub ax, [c]         ; ax = ax - c = a + b - c
        
        ; a, b, c - dword
        ; mov eax, [a]
        ; add eax, [b]        ; eax = eax + b = a + b
        ; sub eax, [c]        ; eax = eax - c = a + b - c
    
        ; exit(0)
        push dword 0        ; push the parameter for exit onto the stack
        call [exit]         ; call exit to terminate the program
