; Se dau 2 siruri de octeti A si B. Sa se construiasca sirul R care sa contina elementele lui B in ordine inversa urmate de elementele in ordine inversa ale lui A.
;   Exemplu:
;   A: 2, 1, -3, 0
;   B: 4, 5, 7, 6, 2, 1
;   R: 1, 2, 6, 7, 5, 4, 0, -3, 1, 2
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    a db 2, 1, -3, 0
    len_a equ $-a
    b db 4, 5, 7, 6, 2, 1
    len_b equ $-b
    r times len_a+len_b db 0
    
segment code use32 class=code
    start:
        mov edi, 0
        
        ; sir b
        mov ecx, len_b
        jecxz peste
        mov esi, 0
        repeta_b:
            mov al, [b+ecx-1]
            mov [r+edi], al
            inc(edi)
        loop repeta_b
        
    peste:
    
        ; sir a
        mov ecx, len_a
        jecxz final
        mov esi, 0
        repeta_a:
            mov al, [a+ecx-1]
            mov [r+edi], al
            inc(edi)
        loop repeta_a
        
    final:
    push dword 0
    call [exit]