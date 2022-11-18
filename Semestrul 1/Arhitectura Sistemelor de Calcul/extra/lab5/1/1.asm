;   Se da un sir de octeti S de lungime l. Sa se construiasca sirul D de lungime l-1 astfel incat elementele din D sa reprezinte produsul dintre fiecare 2 elemente consecutive S(i) si S(i+1) din S.
;   Exemplu:
;   S: 1, 2, 3, 4
;   D: 2, 6, 12
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db 1, 2, 3, 4
    len equ $-s
    d times len dw 0

segment code use32 class=code
    start:
        mov ecx, len-1
        jecxz final
        mov esi, 0
        mov edi, 0
        
        repeta:
            mov al, [s+esi]
            mov bl, [s+esi+1]
            mul bl
            mov [d+edi], ax
            
            inc(esi)
            inc(edi)
        loop repeta
        
        final:
    push dword 0
    call [exit]