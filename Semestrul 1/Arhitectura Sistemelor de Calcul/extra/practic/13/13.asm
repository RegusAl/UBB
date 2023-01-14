; Se citeste de la tastatura un cuvant (sir de caractere de maxim 20 de caractere) si un numar reprezentat pe un octet.
; Daca numarul este impar se cere criptarea cuvantului prin adunarea la fiecare caracter a numarului citit modulo 20. Daca numarul este par se cere criptarea cuvantului prin adaugarea dupa fiecare consoana a gruparii "p"+consoana. Se cere afisarea cuvantului criptat

bits 32 

global start

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    cuvant times 20 db 0
    numar dd 0
    doi dd 2
    modul dd 20
    cuvant_criptat times 20 db 0
    format_dec db "%d", 0
    format_string db "%s", 0


segment code use32 class=code
    start:
    
        ; citire cuvant
        push dword cuvant
        push dword format_string
        call [scanf]
        add esp, 2*4
        
        ; citire numar
        push dword numar
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        mov eax, [numar]
        mov edx, 0
        div dword [doi]
        cmp edx, 0
        je par
        jne impar
        
        impar:
        mov esi, cuvant
        mov edi, cuvant_criptat
        cld
        mov eax, [numar]
        mov edx, 0
        div dword [modul]
        repeta_impar:
        
            lodsb
            
            cmp al, 0
            je final
            
            add al, dl 
            
            stosb
        
        jmp repeta_impar
        
        par:
        mov esi, cuvant
        mov edi, 0
        cld
        repeta_par:
        
            lodsb
            cmp al, 0
            je final
            
            cmp al, 'a'
            je vocala
            
            cmp al, 'e'
            je vocala
            
            cmp al, 'i'
            je vocala
            
            cmp al, 'o'
            je vocala
            
            cmp al, 'u'
            je vocala
            
            mov bl, 'p'
            mov [cuvant_criptat+edi], al
            inc(edi)
            mov [cuvant_criptat+edi], bl
            inc(edi)
            mov [cuvant_criptat+edi], al
            inc(edi)
            
            jmp repeta_par
            
            vocala:
            
            mov [cuvant_criptat+edi], al
            inc(edi)
        
        jmp repeta_par
        
        final:
        ; afisare cuvant criptat
        push dword cuvant_criptat
        call [printf]
        add esp, 1*4
    
    push dword 0
    call [exit]