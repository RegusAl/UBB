; Se da un sir de octeti S. Sa se obtina in sirul D multimea elementelor din S.
;   Exemplu:
;   S: 1, 4, 2, 4, 8, 2, 1, 1
;   D: 1, 4, 2, 8
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db  1, 4, 2, 4, 8, 2, 1, 1
    len equ $-s
    d times len db 0
    
segment code use32 class=code
    start:
        mov ecx, len
        jecxz final
        
        mov esi, 0
        mov edi, 0

        repeta:
            mov al, [s+esi]
            push ecx
            mov ecx, edi
            jecxz adaugare
            mov edx, 0
            
                exista:
                    mov bl, [d+edx]
                    inc(edx)
                    cmp al, bl
                    je peste
                loop exista
            
            adaugare:
                mov [d+edi], al
                inc(edi)
            
            peste:
                inc(esi)
        
            pop ecx
        loop repeta
        
    final:
    push dword 0
    call [exit]