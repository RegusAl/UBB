bits 32

global start

extern exit
import exit msvcrt.dll

; a - byte, b - word, c - double word, d - qword
segment data use32 class=data
    a db 66h
    b dw 1234h
    c dd 12345678h
    d dq 1111111111111111h
    
; (d-c)+(b-a)-(b+b+b) 
segment code use32 class=code
    start:
        
        ; d - c
        mov eax, [d]
        mov edx, [d+4]              ; EDX:EAX = d
        sub eax, dword [c]
        sbb edx, dword 0         ; EDX:EAX = d - c
        
        ; b - a
        mov bx, [b]                     ; BX = b
        mov cl, [a]                      ; CL = a
        mov ch, 0                       ; CX = a
        sub bx, cx                      ; BX = BX - CX = b - a
        
        ; b + b + b
        mov cx, [b]
        add cx, [b]
        add cx, [b]                      ; CX = b + b + b
        
        ; (b-a) - (b + b + b)
        sub bx, cx                      ; BX = BX - CX
        
    
        mov cx, bx                     ; CX = BX
        
        mov ebx, edx                ; EBX = EDX
        mov dx, 0                       ; DX = 0
        
        push dx         
        push cx
        pop ecx                          ; ECX = DX:CX
        
        sub eax, ecx                 ; EAX = EAX - ECX
        mov edx, ebx                ; EDX = EBX
        sbb edx, 0                 
        
        ; EDX:EAX
        
        push dword 0
        call [exit]