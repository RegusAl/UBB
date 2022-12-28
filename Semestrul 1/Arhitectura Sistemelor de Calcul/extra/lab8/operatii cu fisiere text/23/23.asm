; Se da numele unui fisier si un numar pe cuvant scris in memorie. Sa se scrie cifrele hexazecimale ale acestui numar ca text in fisier, fiecare cifra pe o linie separata.  
bits 32
global start

extern exit, fopen, fprintf, fclose
import exit msvcrt.dll
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll

segment data use32 class=data
    nume_fisier db "fisier.txt", 0
    mod_acces db "w", 0
    descriptor_fisier dd -1
    numar dw 1324
    cifra dd 0
    format_hex db "%x            ", 0
    hexa db 16
    
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
        
        repeta:
        
            mov dx, 0
            mov ax, [numar]
            div word [hexa]
            mov [cifra], dx
            mov [numar], ax
            
            push dword [cifra]
            push dword format_hex
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 3*4
            
        cmp word [numar], 0
        jne repeta
        
        peste:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
    
    final:
    
    push dword 0
    call [exit]