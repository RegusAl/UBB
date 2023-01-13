; Se citeste de la tastatura un sir de caractere (litere mici si litere mari, cifre, caractere speciale, etc). Sa se formeze un sir nou doar cu literele mici si un sir nou doar cu literele mari. Sa se afiseze cele 2 siruri rezultate pe ecran.
bits 32

global start

extern exit, gets, printf
import exit msvcrt.dll
import gets msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    text times 100 db 0
    sir_litere_mici times 100 db 0
    sir_litere_mari times 100 db 0
    format_string db "%s", 10, 13, 0

segment code use32 class=code
    start:
    
        ; citire sir de caractere
        push dword text
        call [gets]
        add esp, 1*4
        
        ; formare siruri
        mov esi, text
        mov edi, 0
        mov ebx, 0
        cld
        repeta:
        
            lodsb           ; al = text[esi]
            
            cmp al, 0
            je gata
        
            cmp al, 'a'
            jl nu_litere_mici
            
            cmp al, 'z'
            jg nu_litere_mici
            
            mov [sir_litere_mici+edi], al
            inc(edi)
            
            nu_litere_mici:
            
            cmp al, 'A'
            jl nu_litere_mari
            
            cmp al, 'Z'
            jg nu_litere_mari
            
            mov [sir_litere_mari+ebx], al
            inc(ebx)
            
            nu_litere_mari:
             
        jmp repeta
        
        gata:
        
        push dword sir_litere_mici
        push dword format_string
        call [printf]
        add esp, 2*4
        
        push dword sir_litere_mari
        push dword format_string
        call [printf]
        add esp, 2*4
        
    push dword 0
    call [exit]