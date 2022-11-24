; Se dau doua siruri de caractere S1 si S2. Sa se construiasca sirul D prin concatenarea elementelor sirului S2 in ordine inversa cu elementele de pe pozitiile pare din sirul S1.
;   Exemplu:
;    S1: '+', '2', '2', 'b', '8', '6', 'X', '8'
;    S2: 'a', '4', '5'
;    D: '5', '4', 'a', '2','b', '6', '8'
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s1 db 'x', '2', '2', 'b', '8', '6', 'X', '8'
    len_s1 equ $-s1
    s2 db 'a', '4', '5'
    len_s2 equ $-s2
    d times len_s1+len_s2 db 0

segment code use32 class=code
    start:
        mov ecx, len_s2
        jecxz final
        mov esi, len_s2-1
        mov edi, 0
        
        repeta_s2:
            mov al, [s2+esi]
            mov [d+edi], al
            dec(esi)
            inc(edi)
        loop repeta_s2

        mov ecx, len_s1
        mov esi, 0
        
        repeta_s1:
            mov al, [s1+esi]
            test esi, 1
            je poz_para
            mov [d+edi], al
            inc(edi)
            poz_para:
            inc(esi)
        loop repeta_s1
       
    final:
    
    push dword 0
    call [exit]