; Se citesc de la tastatura numere (in baza 10) pana cand se introduce cifra 0. Determinaţi şi afişaţi cel mai mic număr dintre cele citite. 
bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    x dd 0
    mesaj_x db "Dati numerrele:  ", 0
    format_dec db "%d", 0
    ok db 0
    minim dd 0
    afisare db "Cel mai mic numar este: %d", 0

segment code use32 class=code
    start:
    
        ; x = 
        push dword mesaj_x
        call [printf]
        add esp, 1*4
        
        ; citim x pana cand x = 0
        citire:
        
            push dword x
            push dword format_dec
            call [scanf]
            add esp, 2*4
            
            mov eax, [x]
            
            ; ne oprim din citire cand x = 0
            cmp byte [x], 0
            je peste
            
            ; comparam sa vedem daca este prima citire
            cmp byte [ok], 1
            je ok_1
            
            mov byte [ok], 1
            mov [minim], eax
            
            ok_1:
            
            ; comparam daca este mai mic decat minimul
            cmp eax, dword [minim]
            jb mai_mare
            mov [minim], eax
            
            mai_mare:
        
        jmp citire
    
    peste:
    
        ; afisare
        push dword [minim]
        push dword afisare
        call [printf]
        add esp, 2*4
        
    push dword 0
    call [exit]