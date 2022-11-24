; Se dau doua siruri de caractere S1 si S2. Sa se construiasca sirul D prin concatenarea elementelor de pe pozitiile pare din S2 cu elementele de pe pozitiile impare din S1.
;   Exemplu:
;   S1: 'a', 'b', 'c', 'd', 'e', 'f'
;   S2: '1', '2', '3', '4', '5'
;   D: '2', '4','a','c','e'
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s1 db 'a', 'b', 'c', 'd', 'e', 'f'
    len_s1 equ $-s1
    s2 db  '1', '2', '3', '4', '5'
    len_s2 equ $-s2
    d times len_s1+len_s2 db 0 

segment code use32 class=code
    start:
        mov esi, 0
        mov edi, 0
        
        mov ecx, len_s2
        jecxz final
        repeta_s2:
            test esi, 1h
            mov al, [s2+esi]
            je pozitie_impara
                mov [d+edi], al
                inc(edi)
            pozitie_impara:
            inc(esi)
        loop repeta_s2
        
        mov esi, 0
        mov ecx, len_s1
        jecxz final
        repeta_s1:
            test esi, 1h
            mov al, [s1+esi]
            jne pozitie_para
                mov [d+edi], al
                inc(edi)
            pozitie_para:
            inc(esi)
        loop repeta_s1
         
    final:
    
    push dword 0
    call [exit]