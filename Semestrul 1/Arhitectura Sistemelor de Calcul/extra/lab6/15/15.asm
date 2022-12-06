; Se da un sir S de dublucuvinte.
; Sa se obtina sirul D format din octetii dublucuvintelor din sirul D sortati in ordine descrescatoare in interpretarea fara semn.
; Exemplu:
; s DD 12345607h, 1A2B3C15h
; d DB 56h, 3Ch, 34h, 2Bh, 1Ah, 15h, 12h, 07h
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s dd 12345607h, 1A2B3C15h
    len equ ($-s)
    d times len db 0
    over db 0

segment code use32 class=code
    start:
        mov ecx, len
        jecxz final
        cld
        mov esi, s
        mov edi, d
        repeta:
            movsb
        loop repeta
        
        ; sortare a sirului d in ordine descrescatoare
        while_loop:
        
            mov ecx, len-1
            jecxz peste
            cld
            mov esi, d
            mov edi, d+1
            mov byte [over], 0
            
            for_loop:
                cmpsb
                jg end_if
                
                    dec(esi)
                    dec(edi)
                    lodsb
                    dec(edi)
                    movsb
                    dec(esi)
                    stosb
                    mov byte [over], 1
 
            end_if:
            loop for_loop
            
        peste:
        
        cmp byte [over], 0
        jne while_loop
        
    final:
    push dword 0
    call [exit]