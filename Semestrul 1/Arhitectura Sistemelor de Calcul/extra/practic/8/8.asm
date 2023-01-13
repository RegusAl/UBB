; Citesc string tastatura, creem fisier string.txt, adaugam in fisier prima data majusculele apoi minusculele invers de cum apar in sir.
bits 32

global start

extern exit, fopen, fclose, fprintf, gets
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import gets msvcrt.dll

segment data use32 class=data
    nume_fisier db "string.txt", 0
    mod_acces db "w", 0
    descriptor_fisier dd -1
    string times 100 db 0
    litere_mari times 100 db 0
    litere_mici times 100 db 0
    text times 100 db 0
    contor db 0
    format_str db "%s", 0
    

segment code use32 class=code   
    start:
    
        ; citire string de la tastatura
        push dword string
        call [gets]
        add esp, 1*4
        
        ; format doua siruri:
        ; litere_mari cu Majuscule
        ; litere_mici cu minuscule
        mov esi, string
        mov edi, 0
        mov ebx, 0
        repeta:
        
           lodsb
           cmp al, 0
           je gata
           
           cmp al, 'A'
           jl min
           
           cmp al, 'Z'
           jg min
           
           mov [litere_mari+edi], al
           inc(edi)
           
           min:
           
           cmp al, 'a'
           jl alt
           
           cmp al, 'z'
           jg alt
           
           mov [litere_mici+ebx], al
           inc(ebx)
           
           alt:
        
        jmp repeta
        
        gata:
        
        ; Punem literele mari invers de cum apar
        mov ecx, edi
        dec(edi)
        mov esi, 0
        punere_litere_mari:
            
            push ecx
            
            mov al, [litere_mari+edi]
            mov [text+esi], al
            dec(edi)
            inc(esi)
            
            pop ecx
        
        loop punere_litere_mari
        
        ; Punem literele mici invers de cum apar
        mov ecx, ebx
        dec(ebx)
        punere_litere_mici:
            
            push ecx
            
            mov al, [litere_mici+ebx]
            mov [text+esi], al
            dec(ebx)
            inc(esi)
            
            pop ecx
        
        loop punere_litere_mici
        
        ; deschidere fisier
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        ; verificare fisier
        cmp eax, 0
        je final
        mov [descriptor_fisier], eax
       
        ; afisare text in fisier
        push dword text
        push dword format_str
        push dword [descriptor_fisier]
        call [fprintf]
        add esp, 3*4
        
        final:
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
    
    push dword 0
    call [exit]