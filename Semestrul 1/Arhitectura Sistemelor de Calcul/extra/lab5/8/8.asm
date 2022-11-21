; Se da un sir de caractere S. Sa se construiasca sirul D care sa contina toate literele mari din sirul S.
;   Exemplu:
;   S: 'a', 'A', 'b', 'B', '2', '%', 'x', 'M'
;   D: 'A', 'B', 'M'
bits 32
global start

extern exit 
import exit msvcrt.dll

segment data use32 class=data
    s db 'a', 'A', 'b', 'B', '2', '%', 'x', 'M'
    len equ $-s
    d times len db 0
    
segment code use32 class=code
    start:
        mov ecx, len                    ; ECX = numarul elementelor sirului s
        jecxz final
        mov esi, 0                        ; ESI = 0
        mov edi, 0                        ; EDI = 0
        repeta:
            mov al, [s+esi]
            cmp al, 'A'                     ; comparam al cu 'A'
            jb alt_caracter               ; 'jump if below' la eticheta alt_caracter
                cmp al, 'Z'                 ; comparam al cu 'Z'
                ja alt_caracter           ; 'jump if above' la eticheta alt_caracter
                    mov [d+edi], al
                    inc(edi)                   
        alt_caracter:
        inc(esi)
        loop repeta
        
    final:
    
    push dword 0
    call [exit]
