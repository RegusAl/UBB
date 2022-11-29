bits 32
global start

extern exit, fopen, fclose, scanf, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    nume_fisier db "test.txt", 0
    mod_acces db 'w', 0
    descriptor_fisier dd 0
    
    mesaj db "Eroare la deschiderea fisierului"
    
segment code use32 class=code
    start:
        ; 1. deschid fisierul
        ; EAX - fopen(nume_fisier, mod_acces)
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        ; 2. verific daca fisierul a fost deschis cu succes
        cmp eax, 0
        je eroare
    
        mov [descriptor_fisier], eax
    
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
        jmp final
        
        eroare:
            push dword [mesaj]
            call [printf]
            add esp, 1*4
    final:
    push dword 0
    call [exit]