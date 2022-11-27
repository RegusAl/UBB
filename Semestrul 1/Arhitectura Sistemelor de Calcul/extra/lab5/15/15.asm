; Se dau 2 siruri de octeti A si B. Sa se construiasca sirul R care sa contina elementele lui B in ordine inversa urmate de elementele impare ale lui A.
;   Exemplu:
;   A: 2, 1, 3, 3, 4, 2, 6
;   B: 4, 5, 7, 6, 2, 1
;   R: 1, 2, 6, 7, 5, 4, 1, 3, 3
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    a db 2, 1, 3, 3, 4, 2, 6
    len_a equ $-a
    b db 4, 5, 7, 6, 2, 1
    len_b equ $-b
    r times len_a+len_b db 0
    
segment code use32 class=code
    start:
        mov edi, 0
        ; sirul b in ordine descrescatoare
        mov ecx, len_b
        jecxz final
        repeta_b:
            mov al, [b+ecx-1]
            mov [r+edi], al
            inc(edi)
        loop repeta_b
        ; elementele impare din sirul a
        mov ecx, len_a
        mov esi, 0
        jecxz final
        repeta_a:
            mov al, [a+esi]
            test al, 1h
            je pare
                mov [r+edi], al
                inc(edi)
            pare:
            inc(esi)
        loop repeta_a
        
    final:
    push dword 0
    call [exit]