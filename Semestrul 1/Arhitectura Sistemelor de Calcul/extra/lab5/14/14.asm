; Se da un sir de octeti S. Sa se construiasca un sir D1 care sa contina toate numerele pozitive si un sir D2 care sa contina toate numerele negative din S.
;   Exemplu:
;    S: 1, 3, -2, -5, 3, -8, 5, 0
;   D1: 1, 3, 3, 5, 0
;   D2: -2, -5, -8
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db 1, 3, -2, -5, 3, -8, 5, 0
    len equ $-s
    d1 times len db 0
    d2 times len db 0
    
segment code use32 class=code
    start:
        mov ecx, len   ; ECX = lungimea sirului s
        jecxz final
        mov edx, 0
        mov esi, 0
        mov edi, 0
        repeta:
            mov al, [s+edx]     ; AL = s[edx]
            cmp al, 0                 ; compara Al cu 0
            jl negative                ; "jump if lower" la eticheta negative - jump daca AL mai mic decat 0 in interpretarea cu semn
                mov [d1+esi], al
                inc(esi)
                jmp peste
            negative:
                mov [d2+edi], al
                inc(edi)
        peste:
        inc(edx)
        loop repeta
        
        
    final:
    push dword 0
    call [exit]