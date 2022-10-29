; interpretare cu semn
bits 32

global start

extern exit
import exit msvcrt.dll

; a-doubleword; b,c-byte; x-qword
segment data use32 class=data
    a dd 24536
    b db 45
    c db 15 
    x dq 80

; (a+b)/(2-b*b+b/c)-x
segment code use32 class=code
    start:  
        
        ; a + b
        mov al, [b]       ; al = b
        cbw                  ; al --> ax            
        cwde                ; ax --> eax
        
        add eax, [a]     ; eax = a + b
        push eax 
        
        ; b * b
        mov al, [b]
        imul byte [b]   ; ax = b * b
        
        ; 2 - (b * b)
        mov bx, 2
        sub bx, ax        ; bx = 2 - ax
        
        ; b / c
        mov al, [b]
        cbw                     ; al --> ax
        idiv byte [c]       ; al = ax / c, ah = ax % c
        
        ; 2 - (b * b) + (b / c)
        cbw                    ; al --> ax
        add bx, ax         ; bx = bx + ax
        
        ; (a+b) / (2-b*b+b/c)
        pop ax
        pop dx              ; dx:ax = a + b
        idiv word bx     ; dx:ax % bx = dx, dx:ax / bx = ax    
        
        cwde     ; ax --> eax
        cdq        ; eax --> edx:eax
        
        sub eax, dword [x]         
        sbb edx, dword [x + 4]     ; edx:eax = (a+b) / (2-b*b+b/c) - x
         
        push dword 0
        call [exit]