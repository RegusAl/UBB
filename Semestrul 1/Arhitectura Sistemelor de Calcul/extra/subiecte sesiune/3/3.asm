;sir de dwords, gasesc byte-ul maxim unsigned, il afisez pe ecran alaturi de suma signed a toti bytii gasiti(la final)
bits 32

global start

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

extern rank_build
global rank

segment data use32 class=data
    sir dd 1234A678h, 12345678h, 1AC3B47Dh, 0FEDC9876h
    len_sir equ ($-sir)/4
    sum db 0
    sir_bytes times len_sir db 0, 0
    max db 0
    format_string db "%s", 0
    format_dec db "%d", 0
    rank times len_sir db 0

segment code use32 class=code
    start:
    
        ; gasire maximul din fiecare dword
        push dword len_sir
        push dword sir
        push dword sir_bytes
        push dword rank
        call rank_build
        add esp, 4*4
        
        pushad
        push dword rank
        ;push dword format_string
        call [printf]
        add esp, 1*4
        popad 
         
        push dword eax
        push dword format_dec
        call [printf]
        add esp, 2*4
    
    
    push dword 0
    call [exit]