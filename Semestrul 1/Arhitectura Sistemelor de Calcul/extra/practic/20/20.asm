; Se citeste de la tastatura un cuvant si un numar. Daca numarul este par se cere criptarea cuvantului prin adunarea la fiecare caracter a numarului 20. Daca numarul este impar se cere criptarea cuvantului prin adaugarea dupa fiecare vocala a gruparii "p"+vocala.Se cere afisarea cuvantului criptat.
; ex: arici 3 => aparipicipi
bits 32

global start

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    numar dd 0
    cuvant times 20 db 0
    cuvant_criptat times 40 db 0
    format_dec db "%d", 0
    format_str db "%s", 0
    doi dd 2
    


segment code use32 class=code
    start:
    
        ; citire cuvant
        push dword cuvant
        push dword format_str
        call [scanf]
        add esp, 2*4
        
        ; citire numar
        push dword numar
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        ; retul va fi in edx
        mov eax, [numar]
        mov edx, 0
        div dword [doi]
        
        mov esi, cuvant
        mov edi, 0
        cmp edx, 0
        jne impar
        je par
        
        ; daca numarul este par
        par:
        
            lodsb
            
            cmp al, 0
            je gata
            
            add al, 20
            mov [cuvant_criptat+edi], al
            inc(edi)
        
        jmp par
        
        jmp peste
        
        ; daca numarul este impar
        impar:
        
            lodsb
            
            cmp al, 0
            je gata
            
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
            
            mov [cuvant_criptat+edi], al
            inc(edi)            
            jmp impar
            
            vocala:
            
                mov [cuvant_criptat+edi], al
                inc(edi)
                mov [cuvant_criptat+edi], byte 'p'
                inc(edi)
                mov [cuvant_criptat+edi], al
                inc(edi)
        
        jmp impar
        
        peste:
        gata:
        ; afisam cuvantul criptat
        push dword cuvant_criptat
        push dword format_str
        call [printf]
        add esp, 2*4
    
    push dword 0
    call [exit]