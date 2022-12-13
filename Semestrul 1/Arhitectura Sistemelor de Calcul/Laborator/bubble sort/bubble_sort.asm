bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    sir db 89, 34, 22, 56, 100, 4, 23, 1, -8
    len equ ($-sir)
    over db 0

segment code use32 class=code
    start:
        
        while_loop:
        
            mov ecx, len-1
            jecxz final_loop
        
            mov esi, sir
            mov edi, sir+1
            cld
            mov byte [over], 0
            
            for_loop:
            
                cmpsb
                jl final_if
                
                    dec(esi)
                    dec(edi)
                    lodsb
                    dec(edi)
                    movsb
                    dec(esi)
                    stosb
                    mov byte [over], 1
                    
                final_if:
            
            loop for_loop
        
        final_loop:
            cmp byte [over], 0
            jne while_loop
    
    
    
    push dword 0
    call [exit]