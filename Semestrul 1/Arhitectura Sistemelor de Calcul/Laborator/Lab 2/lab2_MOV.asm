bits 32

global start        

extern exit
import exit msvcrt.dll

segment data use32 class=data
    ; reprezentarea in memorie a segmentului de date
    ;   a    a+1  a+2  a+3
    ; | 78 | 56 | 34 | 12 | ...
    ; in memorie datele sunt reprezentate LITTLE ENDIAN
    ; (in ordine inversa celei naturale, adica CMPS octet la offset-ul cel mai mic)
    a dd 12345678h

; MOV d, s
; d (destinatie): registru, locatie in memorie
; s (sursa): registru, locatie in memorie, valoare imediata
segment code use32 class=code
    start:
        ; d: registru, s: valoare imediata
        ; valoarea sursa va fi extinsa CU SEMN in registrul destinatie
        mov al, 10101111b   ; al = 10101111b = afh (1 octet)
        mov ax, 12h         ; 12h = 00010010b -> ax = 00000000 00010010 = 0012h (2 octeti)
        mov eax, -1         ; -1 = 11111111b = ffh -> eax = ffffffffh (4 octeti)
        
        ; d: registru, s: locatie in memorie
        ; MOV va citi din memorie UN OCTET de la offset-ul a
        mov al, [a]         ; al = 78h
        
        ; MOV va citi din memorie UN WORD (2 octeti) incepand cu offset-ul a
        ;   a    a+1  a+2  a+3
        ; | 78 | 56 | 34 | 12 | ...
        mov ax, [a]         ; ax = 5678h (in ordine naturala)
        
        ; MOV va citi din memorie UN DWORD (4 octeti) incepand cu offset-ul a
        ;   a    a+1  a+2  a+3
        ; | 78 | 56 | 34 | 12 | ...
        mov eax, [a]        ; eax = 12345678h (in ordine naturala)
    
        ; exit(0)
        push dword 0        ; push the parameter for exit onto the stack
        call [exit]         ; call exit to terminate the program
