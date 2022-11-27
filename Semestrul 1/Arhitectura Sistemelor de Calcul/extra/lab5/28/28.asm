 ; Se dau doua siruri de caractere S1 si S2. Sa se construiasca sirul D prin concatenarea elementelor de pe pozitiile multiplu de 3 din sirul S1 cu elementele sirului S2 in ordine inversa.
;   Exemplu:
;   S1: '+', '4', '2', 'a', '8', '4', 'X', '5'
;   S2: 'a', '4', '5'
;   D: '+', 'a', 'X', '5', '4', 'a'
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s1 db  '+', '4', '2', 'a', '8', '4', 'X', '5'
    len_s1 equ $-s1
    s2 db  'a', '4', '5'
    len_s2 equ $-s2
    d times len_s1+len_s2 db 0
    trei dw 3
    
segment code use32 class=code 
    start:
    mov edi, 0
    ; sirul s1
    mov ecx, len_s1
    jecxz peste
    mov esi, 0
    
    repeta_s1:
        mov bl, [s1+esi]
        mov [d+edi], bl
        inc(edi)
        add esi, 3
        cmp esi, len_s1
        ja sirul_s2       
    loop repeta_s1
    
    peste:
    sirul_s2:
    ; sirul s2
    mov ecx, len_s2
    jecxz final
    repeta_s2:
        mov bl, [s2+ecx-1]
        mov [d+edi], bl
        inc(edi)
    loop repeta_s2
    
    final:
    push dword 0
    call [exit]
