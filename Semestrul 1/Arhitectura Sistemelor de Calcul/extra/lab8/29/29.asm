; Se citesc de la tastatura trei numere a, m si n (a: word, 0 <= m, n <= 15, m > n). Sa se izoleze bitii de la m-n ai lui a si sa se afiseze numarul intreg reprezentat de acesti bitii in baza 10. 
bits 32
global start

extern printf, scanf, exit
import printf msvcrt.dll
import scanf msvcrt.dll
import exit msvcrt.dll

segment data use32 class=data   
   a dd 0
   m dd 0
   n dd 0
   mesaj_a db "a = ", 0
   mesaj_m db "m = ", 0
   mesaj_n db "n = ", 0
   format_dec db "%d", 0
   
    
    

segment code use32 class=code
    start:
        
        ; a = 
        push dword mesaj_a
        call [printf]
        add esp, 1*4
        
        ; citim a
        push dword a
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; m = 
        push dword mesaj_m
        call [printf]
        add esp, 1*4
        
        ; citim m
        push dword m
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; n = 
        push dword mesaj_n
        call [printf]
        add esp, 1*4
        
        ; citim n
        push dword n
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; m - n
        mov eax, [a]
        mov ecx, 32
        sub ecx, [m]
        repeta_l:
            shl eax, 1
        loop repeta_l
        
        mov ecx, 32
        sub ecx, [m]
        sub ecx, [n]
        repeta_r:
            shr eax, 1
        loop repeta_r
        
        ;afisare eax
        push eax
        push dword format_dec
        call [printf]
        add esp, 2*4
        
        
        
        
    push dword 0
    call [exit]