; Se da un sir de caractere S. Sa se construiasca sirul D care sa contina toate caracterele speciale (!@#$%^&*) din sirul S.
; Exemplu:
; S: '+', '4', '2', 'a', '@', '3', '$', '*'
; D: '@','$','*'
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db  '+', '4', '2', 'a', '@', '3', '$', '*'
    len equ ($-s)
    caractere_speciale db '!', '@', '#', '$', '%', '^', '&', '*'
    len_speciale equ ($-caractere_speciale)
    d times len db 0
    
segment code use32 class=code
    start:
        mov ecx, len
        jecxz final
        mov esi, 0
        mov edi, 0
        
        repeta:
        
            mov al, [s+esi]
            push ecx
            mov ecx, len_speciale
            
            repeta_caractere:
                cmp al, [caractere_speciale+ecx]
                jne not_equal
                mov [d+edi], al
                inc(edi)
                not_equal:
                
            loop repeta_caractere

            inc(esi)
            pop ecx
            
        loop repeta
    
        final:
    push dword 0
    call [exit]
