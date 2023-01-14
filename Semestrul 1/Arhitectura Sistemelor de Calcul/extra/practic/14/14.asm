; Se da fișierul ala "preufung.txt", câte conține un text de maxim 200 caractere, conține litere mici, mari, spatii și puncte. 
;Afiseaza pe ecran pe randuri diferite cuvintele cu nr impar de litere și sa se înlocuiască litera din mijloc cu spatiu

bits 32

global start

extern exit, printf, fscanf, fopen, fclose
import exit msvcrt.dll
import printf msvcrt.dll
import fscanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll

segment data use32 class=data
    nume_fisier db "preufung.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    cuvant times 20 db 0
    format_string db "%s", 0
    afisare_cuvant db "%s", 10, 13, 0
    doi dd 2
    


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
        
        ; citire cuvinte
        repeta:

            ; citire
            push dword cuvant
            push dword format_string
            push dword [descriptor_fisier]
            call [fscanf]
            add esp, 3*4
            
            cmp eax, -1
            je final
            
            mov esi, cuvant
            mov ebx, 0
            numara_litere:
                
                lodsb
                
                cmp al, 0
                je gata_numararea
                
                add ebx, 1

            jmp numara_litere
            
            gata_numararea:
            mov eax, ebx
            mov edx, 0
            div dword [doi]
            
            cmp edx, 0
            je par
            
            mov eax, ebx
            mov edx, 0
            div dword [doi]
         
            mov esi, eax
            mov al, [cuvant+esi]
            mov al, ' '
            mov [cuvant+esi], al
            
            peste:
            
            push dword cuvant
            push dword afisare_cuvant
            call [printf]
            add esp, 2*4
            
            par:
        
        jmp repeta
        
        final:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
    
    push dword 0
    call [exit]