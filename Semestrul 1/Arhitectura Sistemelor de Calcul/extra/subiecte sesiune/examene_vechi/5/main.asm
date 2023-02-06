; Se dă un șir de valori numerice întregi reprezentate pe dublucuvinte. 
; Să se tipărească pe ecran stringul pozițiilor dublucuvintelor din șirul de dublucuvinte care au cel de-al doilea octet al reprezentării în baza 16 strict negativ, precum și suma acestor octeți în baza 10. 
bits 32

global start

extern exit, printf
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
    
        mov ecx, len_sir
        mov esi, sir
        mov edi, 0
        cld
        mov edx, '0'               ; numaram locatia
        ;mov ebx, 0               ; suma 
        repeta:
            
            lodsw
            lodsb       ; octetul inferior sin cuvantul superior (al)
            add dl, 1
            cmp al, 0
            jge pozitiv
            
            add bl, al
            
            mov [sir_contor+edi], dl
            inc(edi)
            
            pozitiv:
        
            lodsb
        
        loop repeta
        
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