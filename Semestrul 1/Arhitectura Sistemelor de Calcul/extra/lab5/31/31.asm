 ; Se da un sir de caractere S. Sa se construiasca sirul D care sa contina toate caracterele cifre din sirul S.
;   Exemplu:
;   S: '+', '4', '2', 'a', '8', '4', 'X', '5'
;   D: '4', '2', '8', '4', '5'
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db '+', '4', '2', 'a', '8', '4', 'X', '5'
    len equ $-s
    d times len db 0
    
segment code use32 class=code
    start:
        mov ecx, len
        jecxz final
        mov esi, 0
        mov edi, 0
        repeta:
            mov al, [s+esi]
            cmp al, '0'
            jb peste
            cmp al, '9'
            ja peste
            mov [d+edi], al       
            inc(edi)
        peste:
        inc(esi)
        loop repeta
        
    final:
    push dword 0
    call [exit]