; Se dau in segmentul de date un nume de fisier si un text (poate contine orice tip de caracter). Sa se calculeze suma cifrelor din text. Sa se creeze un fisier cu numele dat si sa se scrie suma obtinuta in fisier. 
bits 32
global start

extern exit, fopen, fprintf, fclose, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    nume_fisier db "fisier.txt", 0
    mod_acces db "w", 0
    descriptor_fisier dd -1
    text db "123ana34 are 498 mere", 0
    len equ $-text
    suma dd 0
    format_dec db "Suma cifrelor este: %d", 0

segment code use32 class=code
    start:
    
        ; calculare suma cifrelor
        mov ecx, len
        mov esi, text
        repeta:
            lodsb
            
            cmp al, '1'
            jne nu_1
            add dword [suma], 1
            nu_1:
            
            cmp al, '2'
            jne nu_2
            add dword [suma], 2
            nu_2:
            
            cmp al, '3'
            jne nu_3
            add dword [suma], 3
            nu_3:
            
            cmp al, '4'
            jne nu_4
            add dword [suma], 4
            nu_4:
            
            cmp al, '5'
            jne nu_5
            add dword [suma], 5
            nu_5:
            
            cmp al, '6'
            jne nu_6
            add dword [suma], 6
            nu_6:
            
            cmp al, '7'
            jne nu_7
            add dword [suma], 7
            nu_7:
            
            cmp al, '8'
            jne nu_8
            add dword [suma], 8
            nu_8:
            
            cmp al, '9'
            jne nu_9
            add dword [suma], 9
            nu_9:
        
        loop repeta
        
        ; afisare suma in consola
        ; push dword [suma]
        ; push dword format_dec
        ; call [printf]
        ; add esp, 2*4
        
        ; deschidere fisier
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        ; verificare fisier
        mov [descriptor_fisier], eax
        cmp eax, 0
        je final
    
        ; scriere in fisier
        push dword [suma]
        push dword format_dec
        push dword [descriptor_fisier]
        call [fprintf]
        add esp, 3*4
        
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
        
        final:
    
    push dword 0
    call [exit]