; Se dau un nume de fisier si un text (definite in segmentul de date). Textul contine litere mici, litere mari, cifre si caractere speciale. Sa se inlocuiasca toate caracterele speciale din textul dat cu caracterul 'X'. Sa se creeze un fisier cu numele dat si sa se scrie textul obtinut in fisier. 
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
    nume_fisier_out db "caracatere_speciale_file.txt", 0  
    mod_acces_out db "w", 0         
    descriptor_fis_out dd -1   
    caractere_speciale db "~`!@#$%^&*()_+-={[}]\|:;'<,.>/?", 0    
    text1 db "aNa!! aRe MERe *s*i* @#pere", 0
    len equ $-text1
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
        
            push ecx
            lodsb
                
            mov ecx, 31
            caracter_special:
                cmp al, [caractere_speciale + ecx]
                je schimba_caracter
            loop caracter_special
            
            jmp peste
            
            schimba_caracter:
                mov al, 'X'
           
            peste:
            
            stosb 

            pop ecx
            
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
