; interpretare fara semn
bits 32

global start

extern exit
import exit msvcrt.dll

; a-doubleword; b,c-byte; x-qword
segment data use32 class=data
    a dd 32143456h
    b db 99h
    c db 10h 
    x dq 1245671135164045h

; 11. (a+b)/(2-b*b+b/c)-x
segment code use32 class=code
    start:
        
        ; a + b
        mov ax, word [a]        
        mov dx, word[a+2]       ; dx:ax = a
        mov bl, [b]
        mov bh, 0                       ; bx = b
        add ax, bx
        adc dx, 0                       ; dx:ax = a + b
        
        ; b * b
        push ax
        ;mov cx, ax                    ; cx = ax
        mov al, [b]
        mov bl, [b]
        mul bl                            ; ax = bl * al
        
        ; 2 - (b * b)
        mov bx, 2
        sub bx, ax                  ; bx = 2 - ax
        
        ; mutam dx si cx in stiva pentru a avea registri
        ;push dx
        ;push cx
        
        ; b / c
        mov al, [b]
        mov ah, 0       ; ax = [b]
        mov cl, [c]      ; cl = [c]
        div cl              ; ah = ax % cl, al = ax / cl
        
        ; (2 - (b * b) + b / c)
        mov ch, 0       ; cx = b / c
        add bx, cx      ; bx = bx + cx
        
       ; (a + b) / (2 - b * b + b / c)  
       ; dx:ax = a + b
        pop ax           
        
        div bx     ; dx = dx:ax % bx, ax = dx:ax / bx
        
        mov dx, 0
        push dx
        push ax         ;dx:ax = ax
        
        pop eax
        mov edx, 0    ; edx:eax = ax
        
        mov ebx, dword [x]
        mov ecx, dword [x+4]      ; ecx:ebx = x
        
        sub eax, ebx        ; eax = eax - ebx
        sbb edx, ecx        ; edx = edx - ecx - CF
         
        ; rezultatul este in edx:eax
        
        
        push dword 0
        call [exit]