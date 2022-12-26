; Se citesc de la tastatura doua numere a si b. Sa se calculeze valoarea expresiei (a/b)*k, k fiind o constanta definita in segmentul de date. Afisati valoarea expresiei (in baza 2). 
bits 32
global start

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    a dd 0
    b dd 0
    k dd 2
    mesaj_a db "a = ", 0
    mesaj_b db "b = ", 0
    format_dec db "%d", 0
    format_str db "%s", 0
    bit times 32 db 0

segment code use32 class=code
    start:
    
        ; a = 
        push dword mesaj_a
        call [printf]
        add esp, 1*4
        
        ; citim a
        push dword a
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; b = 
        push dword mesaj_b
        call [printf]
        add esp, 1*4
        
        ; citim b
        push dword b
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; edx:eax = (a / b) * k
        mov eax, [a]
        cdq
        idiv dword [b]
        mul dword [k]
        
        mov ecx, 32
        mov ebx, eax
        mov edi, bit
        
        repeta:
            shl ebx, 1
            mov al, 0
            adc al, '0'
            stosb
        loop repeta
        
        ; afisare
        push bit  
        push dword format_str
        call [printf]
        add esp, 2*4  
        
    push dword 0
    call [exit]