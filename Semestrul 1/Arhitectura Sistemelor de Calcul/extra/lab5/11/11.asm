; Se da un sir de octeti S. Sa se obtina sirul D1 ce contine toate numerele pare din S si sirul D2 ce contine toate numerele impare din S.
;    Exemplu:
;   S: 1, 5, 3, 8, 2, 9
;   D1: 8, 2
;   D2: 1, 5, 3, 9
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
            test al, 1h
            
            jne impare
            je pare
            
            pare:
                mov [d1+edi], al
                inc(edi)
                jmp peste
                
            impare:
                mov [d2+esi], al
                inc(esi)
                
           peste:     
           inc(edx)
        loop repeta
 
    final:    
    
    push dword 0
    call [exit]