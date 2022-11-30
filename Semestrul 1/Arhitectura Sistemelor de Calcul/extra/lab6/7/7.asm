; Se da un sir de dublucuvinte. Sa se obtina sirul format din octetii superiori ai cuvitelor superioare din elementele sirului de dublucuvinte care sunt divizibili cu 3.
;   Exemplu:
;   Se da sirul de dublucuvinte: s DD 12345678h, 1A2B3C4Dh, FE98DC76h
;   Sa se obtina sirul: d DB 12h.
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s DD 12345678h, 1A2B3C4Dh, 0FE98DC76h
    len equ ($-s)/4
    d times len db 0
    trei db 3

segment code use32 class=code
    start:
        mov ecx, len
        jecxz final
        cld                 ; DF = 0
        mov esi, s
        mov edi, d
        
        repeta:
            lodsd           ; EAX = <DS:ESI>
            ; luam octetul superior din cuvantul superior
            shr eax, 24     ; "shift right" cu 24 biti
            mov bl, al      ; BL = AL
            div byte [trei] ; AH = AX % 3, AL = AX / 3
            cmp ah, 0       ; comparam restul impartirii cu 0
            jne peste       ; daca restul nu este 0 sarim la eticheta peste
            mov al, bl      ; AL = BL
            stosb           ; AL = <ES:EDI>
        peste:
        loop repeta
                
    final:
    push dword 0
    call [exit]