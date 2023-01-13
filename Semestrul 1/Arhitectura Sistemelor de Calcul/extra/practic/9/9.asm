; De la tastatura se citeste un nume de fisier input. Se creaza un alt fisier de output in care se pune continutul fisierului de input cu toate caracterele mici schimbate cu codul lor ascii.
bits 32

global start

extern exit, scanf, fprintf, printf, fopen, fclose, fread
import exit msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll

segment data use32 class=data
    nume_fisier_input times 20 db 0
    mod_acces_input db "r", 0
    descriptor_fisier_input dd -1
    nume_fisier_output db "output.txt", 0
    mod_acces_output db "w", 0
    descriptor_fisier_output dd -1
    text times 100 db 0
    afisare_nume_input db "Dati numele fisierului de input: ", 0
    format_str db "%s", 0
    text_ascii times 100 db 0
    format_char db "%c", 0
    format_dec db "%d", 0
    
    
segment code use32 class=code
    start:
    
        push dword afisare_nume_input
        call [printf]
        add esp, 1*4
        
        push dword nume_fisier_input
        push dword format_str
        call [scanf]
        add esp, 2*4
        
        ; deschidere fisier de input
        push dword mod_acces_input
        push dword nume_fisier_input
        call [fopen]
        add esp, 2*4
        
        ; verificare fisier
        cmp eax, 0
        je final_input
        mov [descriptor_fisier_input], eax
        
        ; citire din fisierul de input
        push dword [descriptor_fisier_input]
        push dword 100
        push dword 1
        push dword text
        call [fread]
        add esp, 4*4
        
        final_input:
        ; inchidere fisier input
        push dword [descriptor_fisier_input]
        call [fclose]
        add esp, 1*4
        
        ; punere in fisierul de output
        
        ; deschidere fisier de output
        push dword mod_acces_output
        push dword nume_fisier_output
        call [fopen]
        add esp, 2*4
        
        ;  verificare fisier
        cmp eax, 0
        je final_output
        mov [descriptor_fisier_output], eax

        mov esi, 0
        ;mov edi, text_ascii
        repeta:
            mov eax, 0
            
            mov al, [text+esi]
            inc(esi)
           
            cmp al, 0
            je gata
            
            cmp al, 'a'
            jl nu_litera_mica
            
            cmp al, 'z'
            jg nu_litera_mica
            
            push dword eax
            push dword format_dec
            push dword [descriptor_fisier_output]
            call [fprintf]
            add esp, 3*4
            
            jmp repeta
            
            nu_litera_mica
            
            push dword eax
            push dword format_char
            push dword [descriptor_fisier_output]
            call [fprintf]
            add esp, 3*4
        
        jmp repeta
        
        gata:
        
        final_output:
        ; inchidere fisier output
        push dword [descriptor_fisier_output]
        call [fclose]
        add esp, 1*4
    
    push dword 0
    call [exit]