; Sa se citeasca de la tastatura un numar hexazecimal format din 2 cifre. Sa se afiseze pe ecran acest numar in baza 10, interpretat atat ca numar fara semn cat si ca numar cu semn (pe 8 biti). 
bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    a db 0
    mesaj_a db "a (byte) = ", 0
    format_hex db "%x", 0
    afisare db "%d, -%d", 0
    
segment code use32 class=code
    start:
    
        ; a = 
        push dword mesaj_a
        call [printf]
        add esp, 1*4
        
        ; citim a
        push dword a
        push format_hex
        call [scanf]
        add esp, 2*4
        
        mov eax, 0
        mov al, 256
        sub al, [a]
        mov ebx, 0
        mov bl, [a]
        
        ; afisare
        push eax
        push ebx
        push dword afisare
        call [printf]
        add esp, 3*4
    
    push dword 0
    call [exit]
