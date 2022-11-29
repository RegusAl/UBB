bits 32
global start

extern exit, scanf, printf
import scanf msvcrt.dll
import printf msvcrt.dll
import exit msvcrt.dll

segment data use32 class=data
    n dd 0
    numere times 100 dd 0
    mesaj db "Dati un sir de numere: ", 0
    format db "%d", 0
    format_tiparire db "%d ", 0
    
; Cititi de la tastatura si afisati un sir de numere intregi.
; (citirea se termina atunci cand utilizatorul introduce numarul ZERO)
segment code use32 class=code
    start:
        cld
        mov edi, numere
        citire:
            push dword mesaj
            call [printf]
            add esp, 1*4
            push dword n
            push dword format
            call [scanf]
            add esp, 2*4
            mov eax, [n]
            cmp eax, 0
            je peste
            stosd
        jmp citire
        
        peste:
        
        mov ecx, 100
        cld
        mov esi, numere
        afisare:
            push ecx
            lodsd
            cmp eax, 0
            je final
            push eax
            push dword format_tiparire
            call [printf]
            add esp, 4*2
            pop ecx
        loop afisare
        final:
        ; exit(0)
        push dword 0        ; push the parameter for exit onto the stack
        call [exit]         ; call exit to terminate the program
