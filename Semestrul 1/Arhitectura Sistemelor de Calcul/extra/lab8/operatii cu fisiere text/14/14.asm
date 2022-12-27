; Se dau un nume de fisier si un text (definite in segmentul de date). Textul contine litere mici, litere mari, cifre si caractere speciale. Sa se transforme toate literele mari din textul dat in litere mici. Sa se creeze un fisier cu numele dat si sa se scrie textul obtinut in fisier. 
bits 32
global start        

extern exit, fopen, fread, fclose, printf, fprintf               
import exit msvcrt.dll    
import fprintf msvcrt.dll                      
import fopen msvcrt.dll  
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    nume_fisier_out db "litere_mici.txt", 0  
    mod_acces_out db "w", 0         
    descriptor_fis_out dd -1         
    len equ 100              
    text1 db "aNa aRe MERe si pere", 0
    text2 times len db 0

segment code use32 class=code
    start:          
        
        mov ecx, len 
        jecxz final
        
        mov esi, text1 
        mov edi, text2 
        cld 
        
        ; loop pentru a compara fiecare caracter din text 
        repeta:
        
            lodsb 
            cmp al, 'A'
            jl peste
            
            cmp al, 'Z'
            jg peste
            
            mov bl, 'a'-'A'
            add al, bl
            
            peste:
            stosb 
            
        loop repeta 
        
        ; deschidere fisier
        push dword mod_acces_out     
        push dword nume_fisier_out
        call [fopen]
        add esp, 4*2               

        ; verificare fisier
        mov [descriptor_fis_out], eax   
        
        cmp eax, 0
        je final

        ; textul se pune in fisier
        push dword text2
        push dword [descriptor_fis_out]
        call [fprintf]
        add esp, 4*2
        
        ; inchidere fisier
        push dword [descriptor_fis_out]
        call [fclose]
        add esp, 4                 
        
      final:
        push dword 0   
        call [exit]
