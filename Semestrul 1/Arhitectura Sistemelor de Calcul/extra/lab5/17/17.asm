; Se dau 2 siruri de octeti S1 si S2 de aceeasi lungime. Sa se construiasca sirul D astfel incat fiecare element din D sa reprezinte maximul dintre elementele de pe pozitiile corespunzatoare din S1 si S2.
;   Exemplu:
;   S1: 1, 3, 6, 2, 3, 7
;   S2: 6, 3, 8, 1, 2, 5
;   D: 6, 3, 8, 2, 3, 7
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s1 db 1, 3, 6, 2, 3, 7
    s2 db 6, 3, 8, 1, 2, 5
    len equ $-s2
    d times len db 0

segment code use32 class=code
    start:
        mov ecx, len
        jecxz final
        mov esi, 0
        mov edi, 0
        
        repeta:
            mov al, [s1+esi]
            mov bl, [s2+esi]
            cmp al, bl
            jl mai_mic                  ; "jump if lower" la eticheta mai_mic
            mov [d+edi], al         ; d[edi] = al
            inc(edi)
            jmp peste
            mai_mic:
            mov [d+edi], bl         ; d[edi] = bl
            inc(edi)
            peste:
            inc(esi)
        loop repeta
        
    final:
    push dword 0
    call [exit]
    