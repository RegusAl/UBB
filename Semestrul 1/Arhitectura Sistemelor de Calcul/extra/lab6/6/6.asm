; Se da un sir de cuvinte s. Sa se construiasca sirul de octeti d, astfel incat d sa contina pentru fiecare pozitie din s:
; - numarul de biti de 0, daca numarul este negativ
; - numarul de biti de 1, daca numarul este pozitiv
;   Exemplu:
;   s: -22, 145, -48, 127
; in binary: 1111111111101010, 10010001, 1111111111010000, 1111111
; d: 3, 3, 5, 7
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s dw -22, 145, -48, 127
    len equ ($-s)/2
    d times len db 0
    saispe dw 16d
    
segment code use32 class=code
    start:
        mov ecx, len            ; ECX = lungimea sirului s
        jecxz final
        cld                             ; DF = 0
        mov esi, s                ; ESI = offset-ul lui s
        mov edi, d                ; EDI = offset-ul lui d
    
    repeta:
            push ecx    
            lodsw                   ; AX = DS:ESI
            mov bx, 0               
            mov ecx, 16d      ; ECX = 16 (deoarece facem 16 decrementari)
            mov dx, ax          ; facem o copie la AX in DX
            
            numara
                shr ax, 1            ; shift-right pe pentru a ne da carry-flag
                adc bx, 0           ; adaugam carryflag-ul in BX
            loop numara   
            
            cmp dx, 0               ; comparam DX cu 0 
            jns pozitiv                ; daca valoarea din DX este pozitiva facem jump la eticheta "pozitiv"
            
            mov dx, [saispe]    ; facem o scadere din 16 pentru a afla numarul de zerouri
            sub dx, bx
            mov bx, dx
            
            pozitiv:
            
            mov ax, bx
            stosb                   ; ES : EDI = AX
            pop ecx      
        
        loop repeta
        
        final:
        
        push dword 0
        call [exit]