; Sa se tipareasca in baza 16 catul si restul impartirii fara semn A / B
; A - maximul valorilor octetilor inferiori
; B - minimul valorilor octetilor superiori
bits 32

global start

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    sir_cuv dw 21520, -6, "xy", 0f5b2h, -129 
    len_sir equ ($-sir_cuv)/2
    max db 0
    min db 0FFh
    afisare db "catul = %xh, restul = %xh", 0

segment code use32 class=code
    start:
    
        mov ecx, len_sir            ; punem in ECX numarul de cuvinte din sir
        mov esi, sir_cuv            
        
        repeta:
            
            lodsb                   ; AL = sir_cuv[esi]
            
            cmp al, [max]           ; comparam octetul inferior cu maximul curent
            jbe nu_max              ; daca nu este mai mare, sare la eticheta nu_max
            
            mov [max], al           ; daca este mai mare, maximul devine al
            
            nu_max:
            
            lodsb                   ; AL = sir_cuv[esi]
            
            cmp al, [min]           ; comparam octetul superior cu minimul curent
            jae nu_min              ; daca nu este mai mic, sare la eticheta nu_min
            
            mov [min], al           ; daca este mai mic, minimul devine al

            nu_min:
        
        loop repeta
        
        ; impartirea                ; ah = [max] % [min] ; al = [max] / [min]
        mov ax, 0
        mov al, [max]
        div byte [min]
        
        mov edx, 0
        mov dl, al
        
        mov ebx, 0
        mov bl, ah
        
        ; afisare in consola
        push dword ebx              ; restul
        push dword edx              ; catul
        push dword afisare          ; formatul de afisare
        call [printf]               ; functia de printare
        add esp, 3*4                ; eliberare stiva
    
    
    push dword 0
    call [exit]