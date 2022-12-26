; Se dau doua numere naturale a si b (a, b: dword, definite in segmentul de date). Sa se calculeze suma lor si sa se afiseze in urmatorul format: "<a> + <b> = <result>"
; Exemplu: "1 + 2 = 3"
; Valorile vor fi afisate in format decimal (baza 10) cu semn.
bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    a dd 13
    b dd -37
    rezultat dd 0
    format_afisare db "%d + %d = %d", 0

segment code use32 class=code
    start:
    
        ; a + b = rezultat
        mov eax, [a]
        add eax, [b]
        mov [rezultat], eax
    
        ; afisare
        push dword [rezultat]
        push dword [b]
        push dword [a]
        push dword format_afisare
        call [printf]
        add esp, 4*4
    
    push dword 0
    call [exit]