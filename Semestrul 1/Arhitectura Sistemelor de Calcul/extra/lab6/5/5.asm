; Se dau doua siruri de octeti s1 si s2. Sa se construiasca sirul de octeti d, care contine pentru fiecare octet din s2 pozitia sa in s1, sau 0 in caz contrar.
;   Exemplu:
;   pos: 1, 2, 3, 4, 5 
;   s1: 7, 33, 55, 19, 46
;   s2: 33, 21, 7, 13, 27, 19, 55, 1, 46 
;   d: 2,  0, 1, 0, 0, 4, 3, 0, 5
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s1 db 7, 33, 55, 19, 46
    lena equ $-s1
    s2 db 33, 21, 7, 13, 27, 19, 55, 1, 46 
    lenb equ $-s2
    d times lenb db 0
    
segment code use32 class=code
    start:
        mov ecx, lenb        ; ciclul se executa de lenb ori
        jecxz final         ; prevenim intrarea intr-un ciclu infinit

        cld                 ; DF = 0
        mov esi, 0         
        mov edi, s1        ; EDI = offset-ul primului element al sirului s1
    
        repeta:
            push ecx      ; salvam valoarea lui ecx in stiva
   
            mov al, [s2+esi] ; punem elemnetele din s2 in al
 
            mov ecx, lena  ; executam 
            mov bl, 0
        
        gasire:
            inc bl
            scasb
            je amgasit
            loop gasire 
    
            mov byte [d+esi],0
    
            jmp peste
        
        amgasit:
        
            mov [d+esi], bl
        
        peste:
        
        mov edi, s1
        inc esi
        pop ecx
        loop repeta
    final:
    push dword 0
    call [exit]