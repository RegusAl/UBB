bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    sir dq 123110110abcb0h, 1116adcb5a051ad2h, 4120ca11d730cbb0h
    len equ ($-sir)/8   ; lungimea in quadword-uri
    opt db 8
    zece dd 10
    suma dd 0           ; suma cifrelor numarului multiplilor de 8
    
; Se da un sir de valori numerice intregi reprezentate pe quadworduri.
; Sa se determine suma cifrelor numarului multiplilor de 8 din sirul octetilor 
; inferiori ai cuvintelor superioare ai dublucuvintelor superioare din elementele sirului de quadworduri.
segment code use32 class=code
    start:
        mov ecx, len
        jecxz sfarsit
        cld             ; DF = 0
        mov esi, sir    ; offset-ul sirului sursa
        mov ebx, 0      ; numarul de multiplii de 8
    repeta:
        ; punem dublucuvintul superior intr-un registru
        lodsd           ; EAX = dublucuvint inferior
        lodsd           ; EAX = dublucuvint superior
        
        ; izolam octetul inferior din cuvantul superior
        shr eax, 16     ; AL <-- octetul inferior
        
        ; verificam daca e divizibil cu 8
        mov ah, 0       ; extindem la AX fara semn
        div byte [opt]  ; AX/8
        cmp ah, 0
        jnz nu_e_multiplu
        
        ; e multiplu
        inc ebx
        
    nu_e_multiplu:
        
    loop repeta
    
        ; calculam suma cifrelor numarului din EBX
        mov eax, ebx
        mov edx, 0              ; EDX:EAX = numarul de multipli de 8
    transf:
            div dword [zece]    ; EAX = catul si EDX = restul (ultima cifra)
            add [suma], edx
            
            cmp eax, 0          ; daca catul este ZERO
            jz sfarsit          ; iesim din bucla
    
            mov edx, 0          ; EAX -> EDX:EAX fara semn
        jmp transf
    
    sfarsit:
        ; exit(0)
        push dword 0            ; push the parameter for exit onto the stack
        call [exit]             ; call exit to terminate the program
