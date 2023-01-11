bits 32

global start

extern exit, printf, fopen, fclose, fscanf
import exit msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fscanf msvcrt.dll

segment data use32 class=data
    nume_fisier db "fisier.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd -1
    cuvant times 20 db 0
    primul_cuvant times 20 db 0
    format_string db "%s", 0
    space db ' ', 0
    punct db '.', 0
    numar_cuvinte dd 0
    format_dec db "Numar de cuvinte: %d.  ", 0
    format_str db "%s", 0
    format_primul_cuvant db "Primul cuvant %s are %d litere ", 0ah
    ok dd 0
    numar_primul_cuvant dd 0
    
segment code use32 class=code
    start:
    
        ; deschidere fisier
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        ; verificare fisier
        cmp eax, [descriptor_fisier]
        je final
        mov [descriptor_fisier], eax
        
        ; citire propozitii
            citire_cuvant:
            
                push dword cuvant
                push dword format_string
                push dword [descriptor_fisier]
                call [fscanf]
                add esp, 3*4
                
                ; vedem daca s-au citit toate cuvintele din fisier
                cmp eax, -1
                je final
                
                ; vedem daca am trercut de primul cuvant din fiecare propozitie
                cmp dword [ok], 0
                jne nu_primul
                
                ; numaram literele primului cuvant
                mov dword [numar_primul_cuvant], 0
                mov esi, cuvant
                mov ebx, 0
                numaratoare_primul_cuvant:
                    lodsb
                    cmp al, 0
                    je gata_primul_cuvant
                    inc(ebx)
                jmp numaratoare_primul_cuvant
                
                gata_primul_cuvant:
                mov [numar_primul_cuvant], ebx
                
                mov dword [primul_cuvant], 0
                mov ecx, ebx
                
                ; inversam cuvantul in 'primul_cuvant'
                mov esi, 0
                mov edi, ecx
                dec(edi)
                transfer:
                    mov al, [cuvant+esi]
                    mov [primul_cuvant+edi], al
                    inc(esi)
                    dec(edi)
                loop transfer
                
                mov dword [ok], 1
                
                nu_primul:
                
                ; vedem daca am ajuns la finalul propozitiei
                cmp byte [cuvant], "."
                je afisare_numar
                
                cmp byte [cuvant], " "
                je peste_spatiu
                
                ; numar_cuvinte++
                add dword [numar_cuvinte], 1
                
                ; afisare cuvant din propozitie
                push dword cuvant
                push dword format_string
                call [printf]
                add esp, 2*4
                
                peste_spatiu:
                ; afisare spatiu
                push dword space
                call [printf]
                add esp, 1*4
                
                jmp citire_cuvant
                
                afisare_numar:
                
                ; afisare punct
                push dword punct
                push dword format_str
                call [printf]
                add esp, 2*4
                
                ; afisare numar de cuvinte din propozitie
                push dword [numar_cuvinte]
                push dword format_dec
                call [printf]
                add esp, 2*4

                ; afisarea primului cuvant inversat si a numarului de litere a acestuia
                push dword [numar_primul_cuvant]
                push dword primul_cuvant
                push dword format_primul_cuvant
                call [printf]
                add esp, 3*4
                
                mov dword [numar_cuvinte], 0
                mov dword [ok], 0
                
            jmp citire_cuvant
        
        
        final:
        ; inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
    
    
    push dword 0
    call [exit]