bits 32
global start

extern exit, printf, scanf, gets
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
import gets msvcrt.dll

segment data use32 class=data
    sir db "", 0
    format db "%s", 0
    mesaj db "Scrieti o propozitie", 0
    
; Cititi de la tastatura si afisati o propozitie
; (mai multe siruri de caractere separate prin SPATII si care se termina cu caracterul '.')
segment code use32 class=code--
    start:
        
        push dword mesaj
        call [printf]
        add esp, 1*4
        
        push dword sir
        push dword format
        call [gets]
        add esp, 2*4
        
        push dword sir
        call [printf]
        add esp, 1*4
        
        push dword 0        ; push the parameter for exit onto the stack
        call [exit]         ; call exit to terminate the program
