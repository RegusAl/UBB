; Se da un sir de caractere S. Sa se construiasca sirul D care sa contina toate literele mici din sirul S.
;    Exemplu:
;    S: 'a', 'A', 'b', 'B', '2', '%', 'x'
;    D: 'a', 'b', 'x'
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db 'a', 'A', 'b', 'B', '2', '%', 'x', '`'
    len  equ ($-s)
    d times len db 0
    
segment code use32 class=code
    start:
        mov ecx, len
        jecxz final
        mov esi, 0
        mov edi, 0
        
        repeta:
            mov al, [s+esi] 
            
            cmp al, 'a'-1               ; compar al cu 'a'-1
            jbe alt_caracter                         ; "jump if bellow or equal" la eticheta alt_caracter

                cmp al, 'z'              ; compar al cu 'z'
                jnbe alt_caracter                  ; "jump if not bellow or equal" la eticheta alt_caracter
                mov [d+edi], al
                inc(edi)
            
            alt_caracter:
        
            inc(esi)
        loop repeta
        
        
    final:
    
    push dword 0
    call [exit]
