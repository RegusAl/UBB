; Se dau 2 siruri de octeti S1 si S2 de aceeasi lungime. Sa se construiasca sirul D astfel incat fiecare element din D sa reprezinte suma dintre elementele de pe pozitiile corespunzatoare din S1 si S2.
;   Exemplu:
;   S1: 1, 3, 6, 2, 3, 2
;   S2: 6, 3, 8, 1, 2, 5
;   D: 7, 6, 14, 3, 5, 7
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s1 db 1, 3, 6, 2, 3, 2
    s2 db 6, 3, 8, 1, 2, 5
    len equ $-s2
    d times len db 0

segment code use32 class=code
    start:
        mov ecx, len
        jecxz final
        mov esi, 0
        repeta:
            mov al, [s1+esi]
            add al, [s2+esi]
            mov [d+esi], al
            inc(esi)
        loop repeta
        
    final:
    push dword 0
    call [exit]