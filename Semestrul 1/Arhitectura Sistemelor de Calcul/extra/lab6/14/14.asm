; Se da un sir S de dublucuvinte.
; Sa se obtina sirul D format din octetii dublucuvintelor din sirul D sortati in ordine crescatoare in interpretarea fara semn.
; Exemplu:
; s DD 12345607h, 1A2B3C15h
; d DB 07h, 12h, 15h, 1Ah, 2Bh, 34h, 3Ch, 56h
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s dd 12345607h, 1A2B3C15h
    len equ $-s
    d times len db 0
    over db 0

segment code use32 class=code
    start:
        mov ecx, len
        cld
        mov esi, s
        mov edi, d
        
        repeta:
           movsb 
        loop repeta
        
        cld
        
        while_loop:
        
            mov ecx, len-1
            jecxz end_loop
        
            mov esi, d
            mov edi, d+1
            mov byte [over], 0
            
            for_loop:
                cmpsb
                jl end_if
                
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
        
        end_loop:
        cmp byte [over], 0
        jne while_loop
    
    push dword 0
    call [exit]
