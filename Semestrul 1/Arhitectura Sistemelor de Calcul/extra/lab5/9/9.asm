; Se da un sir de octeti S de lungime l. Sa se construiasca sirul D de lungime l-1 astfel incat elementele din D sa reprezinte diferenta dintre fiecare 2 elemente consecutive din S.
;   Exemplu:
;   S: 1, 2, 4, 6, 10, 20, 25
;   D: 1, 2, 2, 4, 10, 5
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db 1, 2, 4, 6, 10, 20, 25
    len equ ($-s)
    d times len-1 db 0

segment code use32 class=code
    start:
        mov ecx, len-1
        jecxz final
        mov esi, 0
        mov edi, 0
        repeta:
            mov al, [s+esi]
            
            cmp al, [s+esi+1]
            jg mai_mare
                mov al, [s+esi+1]
                sub al, [s+esi]
                jmp initializare
            mai_mare:
            sub al, [s+esi+1]
            initializare:
            mov [d+edi], al
            inc(esi)
            inc(edi)
        loop repeta
        
    final:    
        
    push dword 0
    call [exit]
