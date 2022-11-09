bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s1 db 7, 3, 9, 1, 5
    s2 db 2, 4, 6, 8, 10
    
; Se dau 2 siruri de numere intregi s1 si s2 de lungimi egale.
; Se cere sirul de numere intregi d obtinut astfel:
; - d[i] = s1[i] - s2[i], daca s1[i] > s2[i]
; - d[i] = s2[i] - s1[i], altfel.
segment code use32 class=code
    start:
        
        
        ; exit(0)
        push dword 0        ; push the parameter for exit onto the stack
        call [exit]         ; call exit to terminate the program
