; Să se scrie un program în limbaj de asamblare care:
    ; citește de la tastatură numele unui fișier text;
    ; citește toate numerele întregi din fișierul dat;
    ; determină și afișează pe ecran numărul întreg MAXIM aflat pe o poziție PARĂ în fișier.
; Primul număr din fișier se află pe poziția 0.
; Fișierul text trebuie să existe și va conține doar numere întregi separate prin spații.
;   Exemplu:
;       Dacă fișierul conține:
;       3 -35 1 20 5 -6 9 18 7 -41 4 15 6 -8
;       se va afișa pe ecran:
;       Maxim pozitii pare: 9
bits 32

global start

extern exit, fopen, fclose, fscanf, printf, scanf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fscanf msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    nume_fisier times 30 db 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    citire_fisier db "Dati numele fisierului: ", 0
    format_string db "%s", 0
    format_dec db "%d", 0
    numar dd 0
    doi dd 2
    maxim dd 0
    format_afisare db "Maxim pozitii pare: %d", 0
    format_warning db "Fisierul nu a fost deschis cu succes!"
    
segment code use32 class=code
    start:
    
        ; citire nume de fisier de la tastatura
        push dword citire_fisier
        call [printf]
        add esp, 1*4
        
        push dword nume_fisier
        push dword format_string
        call [scanf]
        add esp, 2*4
        
        ; deschidere fisier
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        ; verificare fisier
        cmp eax, 0
        je warning
        mov [descriptor_fisier], eax
        
        ; citire numere din fisier
        mov ebx, 0      ; in ebx punem pozitia numarului
        citire:
            
            ; citim numarul din fisier
            push dword numar
            push dword format_dec
            push dword [descriptor_fisier]
            call [fscanf]
            add esp, 3*4
            
            ; verificam daca s-a terminat citirea numerelor din fisier
            cmp eax, -1
            je gata
            
            cmp ebx, 0
            jne nu_primul
            mov eax, [numar]
            mov [maxim], eax
            inc(ebx)
            jmp citire
            
            nu_primul:
            
            mov eax, ebx
            mov edx, 0
            div dword [doi]
            inc(ebx)
            
            cmp edx, 0
            jne citire
            
            mov eax, [numar]
            cmp eax, [maxim]
            jl citire
            
            mov [maxim], eax
            
        jmp citire
        gata:
        
            push dword [maxim]
            push dword format_afisare
            call [printf]
            add esp, 2*4
        
        jmp final
            
        warning:
        
            push dword format_warning
            call [printf]
            add esp, 1*4

        final:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
    
    push dword 0
    call [exit]

