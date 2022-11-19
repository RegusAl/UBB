; Se dau doua siruri de octeti S1 si S2 de aceeasi lungime. Sa se construiasca sirul D astfel: fiecare element de pe pozitiile pare din D este suma elementelor de pe pozitiile corespunzatoare din S1 si S2, iar fiecare element de pe pozitiile impare are ca si valoare diferenta elementelor de pe pozitiile corespunzatoare din S1 si S2.
;   Exemplu:
;   S1: 1, 2, 3, 4
;   S2: 5, 6, 7, 8
;   D: 6, -4, 10, -4
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s1 db 1, 2, 3, 4
    len equ $-s1
    s2 db 5, 6, 7, 8
    d times len db 0

segment code use32 class=code
    start:
        mov ecx, len
        jecxz final
        mov esi, 0
        
        repeta:
            mov al, [s1+esi]
            test esi, 00000001h   ; vedem daca bitul cel mai nesemnificativ este 1 sau 0
            
            jnz impar                        ; "jump if not zero" - sare la eticheta impar daca esi este impar
                add al, [s2+esi]           
                jmp final_adunare          ; sare la eticheta final_adunare 
            
            impar:
                sub al, [s2+esi]              
            
            final_adunare:
            mov [d+esi], al
            inc(esi)                            ; incrementam ESI
                    
        loop repeta
    
    final:
    push dword 0
    call [exit]