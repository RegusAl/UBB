; Sa se citeasca de la tastatura doua numere a si b (in baza 10) si sa se calculeze a/b. 
; Catul impartirii se va salva in memorie in variabila "rezultat" (definita in segmentul de date). Valorile se considera cu semn. 
bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    a dd 0
    b dd 0
    mesaj_a db "a = ", 0
    mesaj_b db "b = ", 0
    format db "%d", 0
    rezultat dd 0
    format_afisare db "Rezultatul este: %d", 0
    
segment code use32 class=code
    start:
        
        ; a = 
        push dword mesaj_a
        call [printf]
        add esp, 1*4
        
        ; citim numarul a
        push dword a
        push dword format
        call [scanf]
        add esp, 2*4

        ; b = 
        push dword mesaj_b
        call [printf]
        add esp, 1*4
        
        ; citim numarul b
        push dword b
        push dword format
        call [scanf]
        add esp, 2*4

        ; a / b cu semn
        mov eax, [a]
        cdq
        idiv dword [b]
        mov [rezultat], eax 
        
        ; afisam rezultatul
        push dword [rezultat]
        push dword format_afisare
        call [printf]
        add esp, 2*4
        
    push dword 0
    call [exit]
