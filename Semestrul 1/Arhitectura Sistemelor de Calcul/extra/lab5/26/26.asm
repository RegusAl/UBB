; Se da un sir de octeti S. Sa se determine maximul elementelor de pe pozitiile pare si minimul elementelor de pe pozitiile impare din S.
;   Exemplu:
;   S: 1, 4, 2, 3, 8, 4, 9, 5
;   max_poz_pare: 9
;   min_poz_impare: 3
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db 1, 4, 2, 3, 8, 4, 9, 5
    len equ $-s
    max_poz_pare resb 1
    min_poz_impare resb 1

segment code use32 class=code
    start:
        mov ecx, len
        jecxz final
        mov esi, 0
        repeta:
        
            mov al, [s+esi]
            cmp esi, 0
            je initializare
            test esi, 1h
            
            je poz_pare
            cmp al, [min_poz_impare]
            jge peste
            mov [min_poz_impare], al
            
            poz_pare:
            cmp al, [max_poz_pare]
            jle peste
            mov [max_poz_pare], al

            peste:
                jmp sari
            
            initializare:
                mov [max_poz_pare], al
                inc(esi)
                mov al, [s+esi] 
                mov [min_poz_impare], al
            
            sari:
            inc(esi)
        loop repeta
        
        
    final:    
    push dword 0
    call [exit]
