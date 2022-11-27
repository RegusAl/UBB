; Se dau 2 siruri de octeti A si B. Sa se construiasca sirul R care sa contina doar elementele impare si pozitive din cele 2 siruri.
;   Exemplu:
;   A: 2, 1, 3, -3
;   B: 4, 5, -5, 7
;   R: 1, 3, 5, 7
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    a db 2, 1, 3, -3
    len_a equ $-a
    b db 4, 5, -5, 7
    len_b equ $-b
    r times len_a+len_b db 0 

segment code use32 class=code
    start:
        mov edi, 0
        ; sirul a
        mov ecx, len_a
        jecxz final
        mov esi, 0
        repeta_a:
            mov al, [a+esi]
            cmp al, 0
            jl negativ_a
            test al, 1h
            je par_a
            mov [r+edi], al
            inc(edi)
            negativ_a:
            par_a:
            inc(esi)
        loop repeta_a
        
        ; sirul b
        mov ecx, len_b
        jecxz final
        mov esi, 0
        repeta_b:
            mov al, [b+esi]
            cmp al, 0
            jl negativ_a
            test al, 1h
            je par_a
            mov [r+edi], al
            inc(edi)
            negativ_b:
            par_b:
            inc(esi)
        loop repeta_b
        
    final:
    push dword 0
    call [exit]