 ; Se da un sir de octeti S de lungime l. Sa se construiasca sirul D de lungime l-1 astfel incat elementele din D sa reprezinte catul dintre fiecare 2 elemente consecutive S(i) si S(i+1) din S.
;    Exemplu:
;   S: 1, 6, 3, 1
;   D: 0, 2, 3
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db 1, 6, 3, 1
    len equ $-s-1
    d times len db 0
    
segment code use32 class=code
    start:
        mov ecx, len
        jecxz final
        mov esi, 0
        mov edi, 0
        
        repeta:
            mov al, [s+esi]
            mov ah, 0
            inc(esi)
            mov bl, [s+esi]
            div bl                      ; ah = ax % bl, al = ax / bl 
            mov [d+edi], al
            inc(edi)
        loop repeta
        
    final:
    push dword 0
    call [exit]