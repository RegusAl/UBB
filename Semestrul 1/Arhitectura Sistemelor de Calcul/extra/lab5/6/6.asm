; Se da un sir de octeti S. Sa se construiasca sirul D astfel: sa se puna mai intai elementele de pe pozitiile pare din S iar apoi elementele de pe pozitiile impare din S.
;   Exemplu:
;   S: 1, 2, 3, 4, 5, 6, 7, 8
;   D: 1, 3, 5, 7, 2, 4, 6, 8
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db 1, 2, 3, 4, 5, 6, 7, 8
    len equ $-s
    d times len db 0
    
segment code use32 class=code
    start:
        mov ecx, len/2
        jecxz final
        mov esi, 0
        mov edi, 0
        repeta:
            mov al, [s+esi]
            mov [d+edi], al
            inc(esi)
            mov al, [s+esi]
            mov [d+edi+len/2], al 
            inc(edi)
            inc(esi)
        loop repeta   
    final:
    
    push dword 0
    call [exit]