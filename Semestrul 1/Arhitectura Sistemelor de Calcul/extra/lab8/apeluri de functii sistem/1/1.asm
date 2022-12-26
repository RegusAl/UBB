; Sa se citeasca de la tastatura doua numere (in baza 10) si sa se calculeze produsul lor. 
; Rezultatul inmultirii se va salva in memorie in variabila "rezultat" (definita in segmentul de date). 
bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    a dd 0
    b dd 0
    rezultat times 2 dd 0
    format db "%d", 0
    mesaj_a db "a = ", 0
    mesaj_b db "b = ", 0
    format_quad db "Rezultatul este: %lld", 0

segment code use32 class=code
    start:
            
        ; a =     
        push dword mesaj_a
        call [printf]
        add esp, 1*4
        
        ; citirea numarului a
        push dword a
        push dword format
        call [scanf]
        add esp, 2*4

        ; b = 
        push dword mesaj_b
        call [printf]
        add esp, 1*4
        
        ; citirea numarului b
        push dword b
        push dword format
        call [scanf]
        add esp, 2*4

        ; rezultat = a * b
        mov eax, [a]
        imul dword [b]
        mov dword [rezultat], eax
        mov dword [rezultat+4], edx
        
        ; afisare rezultat
        push dword [rezultat+4]
        push dword [rezultat]
        push dword format_quad
        call [printf]
        add esp, 3*4
    
    push dword 0
    call [exit]


