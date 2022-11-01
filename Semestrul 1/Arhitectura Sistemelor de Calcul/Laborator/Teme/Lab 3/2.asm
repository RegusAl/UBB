bits 32

global start

extern exit
import exit msvcrt.dll

; a - byte, b - word, c - double word, d - qword - Interpretare cu semn
segment data use32 class=data
    a db 10h
    b dw 1234h
    c dd 146789A2h
    d dq 5678910111213141h

; 11. d-(a+b+c)-(a+a) 
segment code use32 class=code
    start:
        
        ; a + b + c
        mov al, [a]     ; AL = a
        cbw                ; AL --> AX
        add ax, [b]     ; AX = AX + b
        cwde              ; AX --> EAX
        add eax, [c]  ; EAX = EAX + c
        
        ; a + a
        mov bl, [a]
        add bl, [a]     ; BL = a + a
        
        ; (a + b + c) - (a+a)
        mov ecx, eax    ; ECX = EAX
        mov al, bl           ; AL = BL
        cbw                     ; AL --> AX
        cwde                   ; AX --> EAX
        
        sub ecx, eax    ; ECX = ECX - EAX = (a + b + c) - (a + a)
        
        ; d- ECX
        mov eax, [d]        ; EAX = d (11213141)
        mov edx, [d+4]    ; EDX = [d + 4] (56789101)
        
        sub eax, ecx        ; EAX = EAX - ECX
        sbb edx, 0              ; EDX - 0 - CarryFlag
    
        push dword 0
        call [exit]