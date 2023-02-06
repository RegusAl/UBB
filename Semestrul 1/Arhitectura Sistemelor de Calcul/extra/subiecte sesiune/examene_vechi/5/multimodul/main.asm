; Se dă un șir de valori numerice întregi reprezentate pe dublucuvinte. 
; Să se tipărească pe ecran stringul pozițiilor dublucuvintelor din șirul de dublucuvinte care au cel de-al doilea octet al reprezentării în baza 16 strict negativ, precum și suma acestor octeți în baza 10. 
bits 32

global start, sir_contor

extern exit, printf, functie
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    sir dd 12A63478h, 12345678h, 1A2B3C4Dh, 0FEDC9876h
    len_sir equ ($-sir)/4
    sir_contor times len_sir db 0 
    format_string db "%s", 0
    format_dec db " %d", 0
    
segment code use32 class=code
    start:
    
        push len_sir
        push sir
        mov edi, 0
        cld
        call functie
        add esp, 2*4
   
        push dword sir_contor
        push dword format_string
        call [printf]
        add esp, 2*4
        
        mov al, bl
        cbw
        cwde
        
        push dword eax
        push dword format_dec
        call [printf]
        add esp, 2*4
        
    push dword 0
    call [exit]