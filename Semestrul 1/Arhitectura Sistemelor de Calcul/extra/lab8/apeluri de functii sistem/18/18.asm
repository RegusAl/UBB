; Sa se citeasca de la tastatura un numar in baza 10 si un numar in baza 16. Sa se afiseze in baza 10 numarul de biti 1 ai sumei celor doua numere citite. Exemplu:
; a = 32 = 0010 0000b
; b = 1Ah = 0001 1010b
; 32 + 1Ah = 0011 1010b
; Se va afisa pe ecran valoarea 4. 
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
    format_hex db "%x", 0
    mesaj_a db "a (base10) = ", 0
    mesaj_b db "b (base16) = ", 0
    resultat dd 0
    afisare db "Numarul de biti este: %d", 0

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
        push dword format_hex
        call [scanf]
        add esp, 2*4
        
        ; a + b = eax
        mov eax, [a]
        add eax, [b]
        
        ; ebx = numarul de biti de 1 din eax
        mov ecx, 32
        mov ebx, 0
        repeta:
            shl eax, 1
            adc ebx, 0
        loop repeta
        
        ; afisare
        push ebx
        push dword afisare
        call [printf]
        add esp, 2*4
        
    push dword 0
    call [exit]