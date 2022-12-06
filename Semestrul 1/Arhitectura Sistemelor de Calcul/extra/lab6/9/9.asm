; Se da un sir de dublucuvinte. 
; Sa se obtina, incepand cu partea inferioara a dublucuvantului, dublucuvantul format din octetii superiori pari ai cuvintelor inferioare din elementele sirului de dublucuvinte. 
; Daca nu sunt indeajuns octeti se va completa cu octetul FFh.
;   Exemplu:
;   Se da sirul de dublucuvinte: s DD 12345678h, 1A2C3C4Dh, 98FCDD76h, 12783A2Bh
;   Sa se obtina dublucuvant: d DD FF3A3C56h.
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s DD 12345678h, 1A2C3C4Dh, 98FCDD76h, 12783A2Bh
    len equ ($-s)/4
    d times 1 dd 0FFFFFFFFh

segment code use32 class=code
    start:
        mov ecx, len
        clc
        mov esi, s
        mov edi, 0
    
        repeta:
            lodsd    ; AX = <DS:ESI>
            mov bl, ah
            and bl, 1b
            cmp bl, 1
            je peste
            mov [d+edi], ah
            inc(edi)
            
        peste:
        loop repeta
    
    push dword 0
    call [exit]