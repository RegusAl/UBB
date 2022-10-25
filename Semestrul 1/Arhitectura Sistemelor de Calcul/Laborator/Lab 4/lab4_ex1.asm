bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    a dw 0111011101010111b
    b dw 1001101110111110b
    c dw 0
 
; Se dau cuvintele A si B. Se cere cuvantul C format astfel:
; - bitii 0-2 ai lui C coincid cu bitii 10-12 ai lui B
; - bitii 3-6 ai lui C au valoarea 1
; - bitii 7-10 ai lui C coincid cu bitii 1-4 ai lui A
; - bitii 11-12 au valoarea 0
; - bitii 13-15 ai lui C concid cu inversul bitilor 9-11 ai lui B
segment code use32 class=code
    start:
        ; vom forma cuvantul C in registrul BX
        mov bx, 0
    
        ; - bitii 0-2 ai lui C coincid cu bitii 10-12 ai lui B
        mov ax, [b]                 ; AX = b
        and ax, 0001110000000000b   ; izolez bitii 10-12 ai lui B
        mov cl, 10
        ror ax, cl                  ; deplasez bitii 10-12 in pozitia 0-2
        or bx, ax                   ; concatenez rezultatul
        
        ; - bitii 3-6 ai lui C au valoarea 1
        or bx, 0000000001111000b
        
        ; - bitii 7-10 ai lui C coincid cu bitii 1-4 ai lui A
        mov ax, [a]                 ; AX = a
        and ax, 0000000000011110b   ; izolez bitii 1-4 ai lui A
        mov cl, 6
        rol ax, cl                  ; deplasez bitii 1-4 in pozitia 7-10
        or bx, ax                   ; concatenez rezultatul
        
        ; - bitii 11-12 au valoarea 0
        and bx, 1110011111111111b
        
        ; - bitii 13-15 ai lui C concid cu inversul bitilor 9-11 ai lui B
        mov ax, [b]                 ; AX = b
        not ax                      ; inversez cuvantul B
        and ax, 0000111000000000b   ; izolez bitii 9-11 ai lui B
        mov cl, 4
        rol ax, cl                  ; deplasez bitii 9-11 in pozitia 13-15
        or bx, ax                   ; concatenez rezultatul
        
        mov [c], bx                 ; stochez rezultatul in memorie
    
        ; exit(0)
        push dword 0                ; push the parameter for exit onto the stack
        call [exit]                 ; call exit to terminate the program
