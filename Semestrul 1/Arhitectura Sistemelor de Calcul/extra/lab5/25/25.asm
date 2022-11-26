 ; Se dau doua siruri de caractere S1 si S2. Sa se construiasca sirul D ce contine toate elementele din S1 care nu apar in S2.
;    Exemplu:
;   S1: '+', '4', '2', 'a', '8', '4', 'X', '5'
;   S2: 'a', '4', '5'
;   D: '+', '2', '8', 'X'
bits 32 
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s1 db '+', '4', '2', 'a', '8', '4', 'X', '5'
    len_s1 equ $-s1
    s2 db 'a', '4', '5'
    len_s2 equ $-s2
    d times len_s1 db 0

segment code use32 class=code
    start:
        mov ecx, len_s1
        jecxz final
        mov esi, 0
        
        repeta:
            push ecx
            mov al, [s1+esi]
            mov edx, 0
            mov ecx, len_s2
            
            exista:
                mov bl, [s2+edx]
                inc(edx)
                cmp al, bl
                je egale
            loop exista
            
            mov [d+edi], al
            inc(edi)
            
            egale:
            pop ecx
            inc(esi)
        loop repeta
        
    final:
    push dword 0
    call [exit]