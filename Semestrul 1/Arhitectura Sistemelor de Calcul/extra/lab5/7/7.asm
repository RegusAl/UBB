; Se dau doua siruri de octeti S1 si S2 de aceeasi lungime. Sa se obtina sirul D prin intercalarea elementelor celor doua siruri.
;   Exemplu:
;   S1: 1, 3, 5, 7
;   S2: 2, 6, 9, 4
;   D: 1, 2, 3, 6, 5, 9, 7, 4
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s1 db 1, 3, 5, 7
    len equ $-s1
    s2 db 2, 6, 9, 4
    d times len+len db 0
    
segment code use32 class=code
    start:
        mov ecx, len
        jecxz final
        mov esi, 0
        mov edi, 0
        
        repeta:
            mov al, [s1+esi]
            mov [d+edi], al
            inc(edi)
            mov al, [s2+esi]
            mov [d+edi], al
            inc(edi)
            inc(esi)
        loop repeta
        
    final:
    
    push dword 0
    call [exit]