; Se da un sir de dublucuvinte. Sa se ordoneze descrescator sirul cuvintelor inferioare ale acestor dublucuvinte. Cuvintele superioare raman neschimbate.
;   Exemplu:
;       sir DD 12345678h 1256ABCDh, 12AB4344h
;   rezultat:
;       1234ABCDh, 12565678h, 12AB4344h
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    sir dd 12345678h, 1256ABCDh, 12AB4344h
    len equ ($-sir)/4
    cuvinte_inferioare times len dw 0
    rez times len dd 0
    over db 0

segment code use32 class=code
    start:
        
        mov ecx, len
        jecxz final
        cld
        mov esi, sir
        mov edi, cuvinte_inferioare
        ; luam cuvintele inferioare din sirul de dublucuvinte si le punem in cuvinte_inferioare
        repeta:
            movsw
            lodsw
        loop repeta
        
        ; sortarea cuvintelor din cuvinte_inferioare
        while_loop:
            mov ecx, len-1
            jecxz final_loop
            cld
            mov esi, cuvinte_inferioare
            mov edi, cuvinte_inferioare+2
            mov byte [over], 0
            
            for_loop:
                cmpsw
                ja final_if
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
            
        ; concatenam cuvintele inferioare sortate cu cuvintele superioare
        mov ecx, len
        cld
        mov edi, sir
        mov esi, cuvinte_inferioare
        concatenare:
            movsw
            add edi, 2
        loop concatenare
            
    final:
    push dword 0
    call [exit]