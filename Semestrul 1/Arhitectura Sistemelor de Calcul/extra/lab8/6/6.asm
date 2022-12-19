; Se dau doua numere naturale a si b (a: dword, b: word, definite in segmentul de date). Sa se calculeze a/b si sa se afiseze catul impartirii in urmatorul format: "<a>/<b> = <cat>"
; Exemplu: pentru a = 200 si b = 5 se va afisa: "200/5 = 40"
; Valorile vor fi afisate in format decimal (baza 10) cu semn. 
bits 32
global start

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    a dd 200
    b dw 5
    format_afisare db "%d / %d = %d", 0
    
segment code use32 class=code
    start:
    
        ; a / b = cat
        mov ax, [a]
        mov dx, [a+2]
        ; dx = rest, ax = cat
        idiv word [b]
        ; ax -> eax
        cwde
        mov ebx, 0
        mov bx, [b]
        
        ; afisare
        push eax
        push ebx
        push dword [a]
        push dword format_afisare
        call [printf]
        add esp, 4*4
        
    push dword 0
    call [exit]