; Se da un sir S de dublucuvinte.
; Sa se obtina sirul D format din octetii inferiori ai cuvintelor inferioare din elementele sirului de dublucuvinte, care sunt multiplii de 7.
;   Exemplu:
; s DD 12345607h, 1A2B3C15h, 13A33412h
; d DB 07h, 15h
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s dd 12345607h, 1A2B3C15h, 13A33412h
    len equ ($-s)/4
    d times len db 0
    sapte db 7
    
segment code use32 class=code
    start:
        mov ecx, len 
        jecxz final
        cld
        mov esi, s
        mov edi, d
        
        repeta:
            lodsb
            mov bl, al
            mov ah, 0    ; al --> ax
            div byte [sapte] 
            cmp ah, 0
            jne peste
            mov al, bl
            stosb
        peste:
        lodsw
        lodsb
        loop repeta
        
    final:
    push dword 0
    call [exit]