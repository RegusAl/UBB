; Se da un numar natural a (a: dword, definit in segmentul de date). Sa se citeasca un numar natural b si sa se calculeze: a + a/b. Sa se afiseze rezultatul operatiei.
; Valorile vor fi afisate in format decimal (baza 10) cu semn. 
bits 32
global start

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    a dd 20
    b dd 0
    citire db "b = ", 0
    format db "%d", 0
    afisare db "Rezultatul este: %d", 0
    rezultat dd 0

segment code use32 class=code
    start:
    
        ; b = 
        push dword citire
        call [printf]
        add esp, 1*4
 
        ; citire numar de la tastatura
        push dword b
        push dword format
        call [scanf]
        add esp, 2*4
        
        ; a + a / b
        mov eax, [a]
        cdq
        idiv dword [b]
        add eax, [a]
        mov [rezultat], eax

        ; afisare rezultat
        push dword [rezultat]
        push dword afisare
        call [printf]
        add esp, 2*4
    
    push dword 0
    call [exit]