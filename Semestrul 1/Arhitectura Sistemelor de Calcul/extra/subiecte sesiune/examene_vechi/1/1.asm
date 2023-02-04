bits 32

global start

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    sir dd 0AABBCCDDh, 1111_0000_0000_1111b, -160, 0FFFFh, 240, 0FFh, -16, -64
    len_sir equ ($-sir)/4
    saispe dw 16
    format_hexa db "%x ", 0

segment code use32 class=code
    start:
    
        mov ecx, len_sir        ; ECX = lungimea sirului de dublucuvinte
        mov esi, sir        
        repeta:
            
            lodsw               ; AX = sir[ESI]
            
            mov dx, 0           
            mov bx, ax          ; facem o copie a lui AX in BX
            div word [saispe]   ; AX = DX:AX / 16,  DX = DX:AX % 16
            cmp dx, 0           ; daca restul este zero rezulta ca AX este multiplu de 16
            jne nu_multiplu     ; sare la eticheta nu_multiplu daca restul nu este zero (adica daca nu este multiplu de 16)
            
            mov ax, bx          ; AX = BX
            
            cmp ax, 0           ; AX - 0
            jge nu_negativ      ; daca numarul nu este negativ in interpretarea cu semn, sare la eticheta nu_negativ
            
            push ecx            ; punem in stiva ecx deoarece [printf] lucreaza cu stiva
            
            push word 0         ; afisam word-ul ce este multiplu de 16 si este strict negativ
            push ax
            push dword format_hexa
            call [printf]
            add esp, 2*4        ; refacem stiva
            
            pop ecx             ; luam ECX din stiva pentru a putea continua loop-ul
                
            nu_multiplu:        
            nu_negativ:
            
            lodsw               ; luam word-ul superior a dublucuvantului curent (nu facem nimic cu el)
               
        loop repeta
    
    push dword 0
    call [exit]