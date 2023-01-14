; Se citesc 3 numere din fisier. sa se afiseze inmultirea lor pe ecran.
bits 32

global start

extern exit, printf, fscanf, fopen, fclose
import exit msvcrt.dll
import printf msvcrt.dll
import fscanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll

segment data use32 class=data
    nume_fisier db "fisier.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    format db '%d %d %d'
    format_d db '%d'
    a dd -1
    b dd -1
    c dd -1
    aux dd -1
    


segment code use32 class=code
    start:
    
        ; deschidere fisier
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        ; verificare fisier
        cmp eax, 0
        je final
        mov [descriptor_fisier], eax
        
        ;fscanf(descriptor,format,variabile)
        push dword c
        push dword b
        push dword a
        push dword format
        push dword[descriptor_fisier]
        call [fscanf]
        add esp,4*5
        
        mov eax,dword[a]
        mov ebx,dword[b]
        mov ecx,dword[c]
        mul bl ;->rezultat in ax
        mul cx ;rezultat in dx ax
        
        push dx
        push ax
        pop dword[aux]
        
        ;printf(format,variabile)
        push dword[aux]
        push dword format_d
        call [printf]
        add esp,4*2
        
    
    final:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
    
    push dword 0
    call [exit]