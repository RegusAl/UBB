; Sa se citeasca de la tastatura doua numere a si b (in baza 10). Sa se calculeze si sa se afiseze media lor aritmetica in baza 16. 
bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    a dd 0
    b dd 0
    format_dec db "%d", 0
    mesaj_a db "a = ", 0
    mesaj_b db "b = ", 0
    afisare db "Media aritmetica este: %xh", 0

segment code use32 class=code
    start:
    
        ; a = 
        push dword mesaj_a
        call [printf]
        add esp, 1*4
        
        ; citire a
        push dword a
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; b = 
        push dword mesaj_b
        call [printf]
        add esp, 1*4
        
        ; citire b
        push dword b
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; eax = (a + b) / 2
        mov eax, [a]
        add eax, [b]
        cdq
        mov ebx, 2
        idiv ebx
        
        ; afisare (a + b) / 2
        push eax
        push afisare
        call [printf]
        add esp, 2*4
        
    push dword 0
    call [exit]