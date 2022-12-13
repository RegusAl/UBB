; Se da un sir de dublucuvinte. Sa se ordoneze crescator sirul cuvintelor superioare ale acestor dublucuvinte. Cuvintele inferioare raman neschimbate.
;   Exemplu:
;       sir DD 12AB5678h, 1256ABCDh, 12344344h 
;   rezultatul
;       12345678h, 1256ABCDh, 12AB4344h.
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    sir dd 12AB5678h, 1256ABCDh, 12344344h 
    len equ ($-sir)/4
    cuvinte_superioare times len dw 0
    over db 0
    

segment code use32 class=code
    start:
        
        mov ecx, len
        jecxz final
        mov esi, sir
        mov edi, cuvinte_superioare
        cld
        repeta:
            lodsw
            movsw
        loop repeta
        
        while_loop:
        
            mov ecx, len-1
            jecxz final_loop
            
            mov esi, cuvinte_superioare
            mov edi, cuvinte_superioare+2
            cld
            mov byte [over], 0
            
            for_loop:
                cmpsw
                jb final_if
                    sub esi, 2
                    sub edi, 2
                    lodsw
                    sub edi, 2
                    movsw
                    sub esi, 2
                    stosw
                    mov byte [over], 1
            
                final_if:
                
            loop for_loop
            
            final_loop:
            cmp byte [over], 0
            jne while_loop
            
        ; concatenare
        mov ecx, len
        mov esi, cuvinte_superioare
        mov edi, sir
        concatenare:
            add edi, 2
            movsw
        loop concatenare
    final:
    push dword 0
    call [exit]
