; Se dau doua numere natural a si b (a: dword, b: word, definite in segmentul de date). Sa se calculeze a/b si sa se afiseze restul impartirii in urmatorul format: "<a> mod <b> = <rest>"
; Exemplu: pentru a = 23 si b = 5 se va afisa: "23 mod 5 = 3"
; Valorile vor fi afisate in format decimal (baza 10) cu semn. 
bits 32
global start

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    a dd 23
    b dw 5
    format_afisare db "%d mod %d = %d", 0
    _rest dd 0
   
segment code use32 class=code
    start:
        
        ; a % b = rest
        mov ax, [a]
        mov dx, [a+2]
        ; dx = rest, ax = cat
        idiv word [b]
        mov word [_rest], dx
        mov word [_rest+2], 0
        mov ebx, [a]
        mov ax, [b]
        cwde
        
        ; afisare
        push dword [_rest]
        push eax
        push ebx
        push dword format_afisare
        call [printf]
        add esp, 4*4
    
    push dword 0
    call [exit]