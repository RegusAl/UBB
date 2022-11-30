; Se da un sir A de cuvinte. Construiti doua siruri de octeti  
;  - B1: contine ca elemente partea superioara a cuvintelor din A
;  - B2: contine ca elemente partea inferioara a cuvintelor din A
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    A dw 1234h, 1099h, 9912h, 4312h
    len equ ($-A)/2
    B1 times len db 0
    B2 times len db 0

segment code use32 class=code
    start:
        mov ecx, len
        jecxz final
        cld
        mov esi, A
        mov edi, 0
        
        repeta:
            lodsb
            mov [B2+edi], al
            
            lodsb
            mov [B1+edi], al
            
            inc(edi)
        
        loop repeta
        
    final:
    push dword 0
    call [exit]