; Se dau doua siruri de caractere S1 si S2. Sa se construiasca sirul D prin concatenarea elementelor de pe pozitiile impare din S2 cu elementele de pe pozitiile pare din S1.
;   Exemplu:
;   S1: 'a', 'b', 'c', 'b', 'e', 'f'
;   S2: '1', '2', '3', '4', '5'
;   D: '1', '3', '5', 'b', 'b', 'f'
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s1 db 'a', 'b', 'c', 'b', 'e', 'f'
    len_s1 equ $-s1
    s2 db '1', '2', '3', '4', '5'
    len_s2 equ $-s2
    d times len_s1+len_s2 db 0
    
segment code use32 class=code
    start:
        mov edi, 0
        
        ; elementele de pe pozitiile impare din s2
        mov ecx, len_s2
        jecxz final
        mov esi, 0
        repeta_s2:
            test esi, 1h
            jne peste_s2
            mov al, [s2+esi]
            mov [d+edi], al
            inc(edi)
            peste_s2:
            inc(esi)
        loop repeta_s2
        
        ; elementele de pe pozitiile pare din s1
        mov ecx, len_s1
        jecxz final
        mov esi, 0
        repeta_s1:
            test esi, 1h
            je peste_s1
            mov al, [s1+esi]
            mov [d+edi], al
            inc(edi)
            peste_s1:
            inc(esi)
        loop repeta_s1
        
    final:    
    push dword 0
    call [exit]
