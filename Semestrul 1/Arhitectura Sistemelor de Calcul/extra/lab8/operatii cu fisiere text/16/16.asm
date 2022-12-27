;  Se da un fisier text. Sa se citeasca continutul fisierului, sa se contorizeze numarul de litere 'y' si 'z' si sa se afiseze aceaste valori. Numele fisierului text este definit in segmentul de date. 
bits 32
global start

extern exit, fopen, fclose, fread, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    nume_fisier db "fisier.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    len equ 100
    text times len db 0
    nr_y dd 0
    nr_z dd 0
    mesaj_y db "Numarul de litere 'y': %d ", 0
    mesaj_z db "Numarul de litere 'z': %d ", 0
    
segment code use32 class=code
    start:
    
        ; deschidere fisier
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        ; verificare fisier
        mov [descriptor_fisier], eax
        cmp eax, 0
        je final
        
        ; citire text din fisier
        push dword [descriptor_fisier]
        push dword len
        push dword 1
        push dword text
        call [fread]
        add esp, 4*4
        
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
        
        mov ecx, len
        mov esi, text
        repeta:
            lodsb
            cmp al, 'z'
            je numara_Z
            
            cmp al, 'y'
            je numara_Y
            
            jmp peste
            
            numara_Z:
                add dword [nr_z], 1
                jmp peste

            numara_Y:
                add dword [nr_y], 1
                
            peste:
            
        loop repeta
        
        ; afisare numar Z
        push dword [nr_z]
        push dword mesaj_z
        call [printf]
        add esp, 2*4
        
        ; afisare numar Y
        push dword [nr_y]
        push dword mesaj_y
        call [printf]
        add esp, 2*4
        
    final:
    
    push dword 0
    call [exit]