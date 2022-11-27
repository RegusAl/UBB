 ; Se da un sir de octeti S. Sa se construiasca sirul D ale carui elemente reprezinta suma fiecaror doi octeti consecutivi din sirul S.
;   Exemplu:
;   S: 1, 2, 3, 4, 5, 6
;   D: 3, 5, 7, 9, 11
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db 1, 2, 3, 4, 5, 6
    len equ $-s
    d times len-1 db 0
   
segment code use32 class=code
    start:
    
        mov ecx, len-1
        jecxz final
        mov esi, 0
        
        repeta:
            mov al, [s+esi]
            inc(esi)
            mov bl, [s+esi]
            add al, bl
            mov [d+edi], al
            inc(edi)
        loop repeta
       
    final:
    
    push dword 0
    call [exit]