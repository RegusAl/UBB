; Se da un sir de octeti S. Sa se construiasca sirul D1 ce contine elementele de pe pozitiile pare din S si sirul D2 ce contine elementele de pe pozitiile impare din S.
;   Exemplu:
;   S: 1, 5, 3, 8, 2, 9
;   D1: 1, 3, 2
;   D2: 5, 8, 9
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db 1, 5, 3, 8, 2, 9
    len equ $-s
    d1 times len db 0
    d2 times len db 0
    
segment code use32 class=code 
    start:
        mov ecx, len
        jecxz final
        mov edx, 0
        mov esi, 0
        mov edi, 0

        repeta:
            mov al, [s+edx]
            test edx, 1h
            je pare
                mov [d2+edi], al
                inc(edi)
                jmp peste
            pare:
                mov [d1+esi], al
                inc(esi)
        peste:
        inc(edx)
        loop repeta
     
    final:
    push dword 0
    call [exit]