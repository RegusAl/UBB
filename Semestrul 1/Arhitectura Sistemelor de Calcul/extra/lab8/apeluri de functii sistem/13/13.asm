; Sa se citeasca de la tastatura doua numere a si b (in baza 10) si sa se calculeze: (a+b) * (a-b). Rezultatul inmultirii se va salva in memorie in variabila "rezultat" (definita in segmentul de date). 
bits 32
global start

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    a dd 0
    b dd 0
    rezultat dq 0
    mesaj_a db "a = ", 0
    mesaj_b db "b = ", 0
    format db "%d", 0
    afisare_rezultat db "Rezultatul este %d", 0

segment code use32 class=code
    start:
    
        ; a = 
        push dword mesaj_a
        call [printf]
        add esp, 1*4
        
        ; citire a
        push dword a
        push dword format
        call [scanf]
        add esp, 2*4
        
        ; b = 
        push dword mesaj_b
        call [printf]
        add esp, 1*4
        
        ; citire b
        push dword b 
        push dword format
        call [scanf]
        add esp, 2*4
        
        ; (a + b) * (a - b)
        mov eax, [a]
        add eax, [b]
        mov ebx, [a]
        sub ebx, [b]
        mul ebx       ; edx:eax -> (a + b) * (a - b)
        mov [rezultat], eax
        mov [rezultat+4], edx

        ; afisare rezultat
        push dword [rezultat+4]
        push dword [rezultat]
        push dword afisare_rezultat
        call [printf]
        add esp, 3*4
            
    push dword 0
    call [exit]