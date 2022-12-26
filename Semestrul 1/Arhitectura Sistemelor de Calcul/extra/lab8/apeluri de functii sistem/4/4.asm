; Se dau doua numere naturale a si b (a, b: word, definite in segmentul de date). Sa se calculeze produsul lor si sa se afiseze in urmatorul format: "<a> * <b> = <result>"
; Exemplu: "2 * 4 = 8"
; Valorile vor fi afisate in format decimal (baza 10) cu semn. 
bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    a dw 2
    b dw 4
    rezultat dd 0
    format_afisare db "%d * %d = %d", 0

segment code use32 class=code
    start:
    
        ; a * b = rezultat
        mov eax, 0
        mov ax, [a]
        mov bx, [b]
        mul bx
        mov [rezultat], eax
        
        mov ax, [a]
        cwde
        mov ebx, eax
        mov ax, [b]
        cwde
        
        ; afisare rezultat
        push dword [rezultat]
        push dword eax
        push dword ebx
        push dword format_afisare
        call [printf]
        add esp, 4*4
    
    push dword 0
    call [exit]