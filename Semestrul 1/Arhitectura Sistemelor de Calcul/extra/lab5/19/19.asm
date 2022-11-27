; Se dau 2 siruri de octeti A si B. Sa se construiasca sirul R care sa contina doar elementele pare si negative din cele 2 siruri.
;   Exemplu:
;   A: 2, 1, 3, -3, -4, 2, -6
;   B: 4, 5, -5, 7, -6, -2, 1
;   R: -4, -6, -6, -2
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    a db 2, 1, 3, -3, -4, 2, -6
    len_a equ $-a
    b db 4, 5, -5, 7, -6, -2, 1
    len_b equ $-b
    r times len_a+len_b db 0
    
segment code use32 class=code
    start:
        mov edi, 0
        
        ;sirul a
        mov ecx, len_a
        mov esi, 0
        repeta_a:
            mov al, [a+esi]
            cmp al, 0
            jge pozitiv_a
            test al, 1h
            jne impar_a
            mov [r+edi], al
            inc(edi)
            pozitiv_a:
            impar_a:
            inc(esi)
        loop repeta_a
        
        ;sirul b
        mov ecx, len_b
        mov esi, 0
        repeta_b:
            mov al, [b+esi]
            cmp al, 0
            jge pozitiv_b
            test al, 1h
            jne impar_b
            mov [r+edi], al
            inc(edi)
            pozitiv_b:
            impar_b:
            inc(esi)
        loop repeta_b
    
    push dword 0
    call [exit]