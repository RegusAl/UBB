; Se dau 2 siruri de octeti A si B. Sa se construiasca sirul R care sa contina elementele lui B in ordine inversa urmate de elementele negative ale lui A.
    
    ; Exemplu:

    ;   A: 2, 1, -3, 3, -4, 2, 6
    ;   B: 4, 5, 7, 6, 2, 1
    ;   R: 1, 2, 6, 7, 5, 4, -3, -4

bits 32

global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    a db 2, 1, -3, 3, -4, 2, 6
    len_a equ ($-a)
    b db 4, 5, 7, 6, 2, 1
    len_b equ ($-b)
    r times len_b+len_a db 0

segment code use32 class=code
    start:
    
        mov ecx, len_b
        mov esi, 0
        jecxz sfarsit
        ; loop pentru a lua sirul B in ordine inversa 
        repetaB:
            mov al, [b+esi]
            mov [r+ecx-1], al
            inc esi
        loop repetaB
        
        mov ecx, len_a
        mov edi, 0
        mov esi, 0
        jecxz sfarsit
        ; loop pentru a lua numerele negative din sirul A
        repetaA:
            mov al, [a+esi]
            inc esi
            test al, 0F2h ; testam daca SingFlag este 1 sau 0
            jns pozitiv    ; jump la eticheta pozitiv daca SF este 0
                mov [r+len_b+edi], al
                inc edi
            pozitiv:  
        loop repetaA
            
        sfarsit:
    
        push dword 0
        call [exit]