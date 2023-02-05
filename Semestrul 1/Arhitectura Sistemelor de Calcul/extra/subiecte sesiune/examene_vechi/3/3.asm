; Se da un sir de dublucuvinte
; Consideram doar dublucuvintele pozitive din sir
; Sa se afiseze in baza 10 valoarea cuvantului inferior de valoare minima (in interpretarea cu semn)
bits 32

global start

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    sir dd 0F000FFF3h, 1034FF0Fh, 0FFFFFFFFh
    len_sir equ ($-sir)/4
    min dw 7FFFh
    format_dec db "%d", 0
    
segment code use32 class=code
    start:
    
        mov ecx, len_sir
        mov esi, sir
        
        repeta:
        
            lodsd
            cmp eax, 0
            jl negativ
            
            cmp ax, [min]
            jg peste
            
            mov [min], ax
            
            negativ:
            peste:
        
        loop repeta
        
        mov ax, [min]
        cwd
        
        push dword eax
        push dword format_dec
        call [printf]
        add esp, 2*4
    
    push dword 0
    call [exit]
    