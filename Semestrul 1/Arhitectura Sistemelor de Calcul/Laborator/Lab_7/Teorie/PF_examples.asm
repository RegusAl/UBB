bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    
; PF (Parity Flag)
segment code use32 class=code
    start:
    
        xor eax, eax
    
        ; The antiquity of the Parity Flag is proved by the fact that it works on LOW 8 bits ONLY, so it's of limited use.
        ; According to Intel® 64 and IA-32 Architectures Software Developer Manuals the Parity Flag is:
        ; - set if THE LEAST-SIGNIFICANT BYTE OF THE RESULT contains an EVEN number of 1 bits;
        ; - cleared otherwise.
        ; mov al, 1111_1111b
        ; and al, 0000_0001b           ; AL = 0000_0001 => PF = 0 (PF is cleared)
        
        ; mov al, 1111_1111b
        ; and al, 0000_0011b           ; AL = 0000_0011 => PF = 1 (PF is set)
        
        ; PF nu are legatura cu paritatea numarului
        ; O combinatie de biti de forma:
        ; xxxx xxxb
        ; - numar par, daca c.m.p.s. bit e 0
        ; - numar impar, daca c.m.p.s. bit e 1
        mov al, 0000_0000b
        add al, 1100_0000b          ; AL = 1100 0000 - rezultatul e PAR (c.m.p.s. bit e 0), iar PF = 1 (numar PAR de 1)
        
        mov al, 0000_0000b
        add al, 1110_0001b          ; AL = 1110 0001 - rezultatul e IMPAR (c.m.p.s. bit e 1), iar PF = 1 (numar PAR de 1)
    
        ; exit(0)
        push dword 0                ; push the parameter for exit onto the stack
        call [exit]                 ; call exit to terminate the program
