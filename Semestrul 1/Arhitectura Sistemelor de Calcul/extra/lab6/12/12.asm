; Se da un sir A de dublucuvinte. Cunstruiti doua siruri de octeti  
;  - B1: contine ca elemente partea inferioara a cuvintelor inferioara din A
;  - B2: contine ca elemente partea superioara a cuvintelor superioare din A
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    A dd 12345678h, 55667788h, 90123214h, 11223344h
    len equ ($-A)/4
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
            lodsb                   ; AL = <DS:ESI>
            mov [B1+edi], al
            
            lodsw
            
            lodsb
            mov [B2+edi], al

            inc(edi)
        loop repeta
          
    final:
    push dword 0
    call [exit]