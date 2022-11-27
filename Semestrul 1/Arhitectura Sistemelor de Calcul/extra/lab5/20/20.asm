; Se dau 2 siruri de octeti A si B. Sa se construiasca sirul R care sa contina elementele lui B in ordine inversa urmate de elementele pare ale lui A.
;    Exemplu:
;   A: 2, 1, 3, 3, 4, 2, 6
;   B: 4, 5, 7, 6, 2, 1
;   R: 1, 2, 6, 7, 5, 4, 2, 4, 2, 6
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    a db 2, 1, 3, 3, 4, 2, 6
    len_a equ $-a
    b db  4, 5, 7, 6, 2, 1
    len_b equ $-b
    r times len_a+len_b db 0
    
segment code use32 clas=code
    start:
        mov edi, 0
        ; sirul b
        mov ecx, len_b
        jecxz peste_b
        repeta_b:
            mov al, [b+ecx-1]
            mov [r+edi], al
            inc(edi)
        loop repeta_b
                
        peste_b:
        ; sirul a
        mov ecx, len_a
        jecxz final
        mov esi, 0
        repeta_a:
            mov al, [a+esi]
            test al, 1h
            jne impare
            mov [r+edi], al
            inc(edi)
            impare:
            inc(esi)
        loop repeta_a
        
        final:    
    push dword 0
    call [exit]
