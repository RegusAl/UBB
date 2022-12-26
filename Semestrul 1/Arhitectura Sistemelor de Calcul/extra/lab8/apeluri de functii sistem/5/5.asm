; Se dau doua numere naturale a si b (a, b: word, definite in segmentul de date). Sa se calculeze a/b si sa se afiseze catul si restul impartirii in urmatorul format: "Cat = <cat>, rest = <rest>"
;   Exemplu: pentru a=23 si b=10 se va afisa: "Cat = 2, rest = 3"
;   Valorile vor fi afisate in format decimal (baza 10) cu semn.
bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    a dw 23
    b dw 10
    format_afisare db "Cat = %d, rest = %d", 0

segment code use32 class=code
    start:
    
        ; a / b cu semn
        mov ax, [a]
        cwd
        ; dx = restul, ax = catul
        idiv word [b]
    
        ; ax -> ebx, dx -> eax
        cwde
        mov ebx, eax
        mov ax, dx
        cwde
    
        ; afisare
        push eax
        push ebx
        push format_afisare
        call [printf]
        add esp, 3*4
       
    push dword 0
    call [exit]