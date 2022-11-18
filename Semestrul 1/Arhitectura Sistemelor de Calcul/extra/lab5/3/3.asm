; Se dau doua siruri de octeti S1 si S2. Sa se construiasca sirul D prin concatenarea elementelor din sirul S1 luate de la stanga spre dreapta si a elementelor din sirul S2 luate de la dreapta spre stanga.
;   Exemplu:
;       S1: 1, 2, 3, 4
;       S2: 5, 6, 7
;       D: 1, 2, 3, 4, 7, 6, 5
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s1 db 1, 2, 3, 4
    len_s1 equ $-s1
    s2 db 5, 6, 7
    len_s2 equ $-s2
    d times (len_s1 + len_s2) db 0

segment code use32 class=code
    start:
        mov ecx, len_s1
        jecxz final
        mov esi, 0
        mov edi, len_s2-1
        
        construire_sir1:
            mov al, [s1+esi]
            mov [d+esi], al
            inc(esi)
        loop construire_sir1
        
        mov ecx, len_s2
        jecxz final

        construire_sir2:
            mov al, [s2+edi]
            mov [d+esi], al
            dec(edi)
            inc(esi)
        loop construire_sir2
     
        final:
     
    push dword 0
    call [exit]