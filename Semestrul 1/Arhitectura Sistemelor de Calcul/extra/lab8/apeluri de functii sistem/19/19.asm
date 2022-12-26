; Sa se citeasca de la tastatura un octet si un cuvant. Sa se afiseze pe ecran daca bitii octetului citit se regasesc consecutiv printre bitii cuvantului. Exemplu:
; a = 10 = 0000 1010b
; b = 256 = 0000 0001 0000 0000b
; Pe ecran se va afisa NU.
; a = 0Ah = 0000 1010b
; b = 6151h = 0110 0001 0101 0001b
; Pe ecran se va afisa DA (bitii se regasesc pe pozitiile 5-12).
bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    a dd 0
    b dd 0
    mesaj_a db "a = ", 0
    mesaj_b db "b = ", 0
    format_dec db "%d", 0
    da db "DA", 0
    nu db "NU", 0

segment code use32 class=code
    start:
    
        ; a = 
        push dword mesaj_a
        call [printf]
        add esp, 1*4
        
        ; citire a
        push dword a
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; b = 
        push dword mesaj_b
        call [printf]
        add esp, 1*4
        
        ; citire b
        push dword b
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; mutam word-ul in ax si byte-ul in bl 
        mov ecx, 8
        mov ax, [b]
        mov bl, [a]
        
        ; comparam al cu bl bit cu bit
        repeta:
            cmp al, bl
            je egal
            shr ax, 1        
        loop repeta
        
            ; daca nu se gasesc bit consecutivi in ax care sa fie egali cu bitii din bl
            push dword nu
            call [printf]
            add esp, 1*4
            jmp peste
        
        egal:
        
            push dword da
            call [printf]
            add esp, 1*4
       
    peste:
    push dword 0
    call [exit]
