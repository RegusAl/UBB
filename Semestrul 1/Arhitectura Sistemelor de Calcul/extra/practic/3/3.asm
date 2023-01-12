; Se citeste o propozitie de la tastatura. Sa se inverseze fiecare cuvant si sa se afiseze pe ecran.
bits 32

global start

extern exit, printf, scanf, gets
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
import gets msvcrt.dll

segment data use32 class=data
    cuvant times 10 db 0
    format_string db "%s", 0
    format_afisare db "%s ", 0
    text times 100 db 0
    destinatie times 100 db 0
    invers times 100 db 0
    

segment code use32 class=code
    start:
    
        push dword text
        call [gets]
        add esp, 2*4
        
        mov esi, text
        mov edi, destinatie
        mov ecx, -1
        
        repeta:
        
            cmp byte [esi], 0
            je final_repeta
            
            cmp byte [esi], ' '
            jne stocheaza_litera
            je inverseaza
            
            stocheaza_litera:
                movsb
                jmp repeta
                
            inverseaza:
                sub edi, 1
                mov ebx, invers
                
                repeta1:
                    cmp edi, destinatie-1
                    je final_repeta1
                    
                    mov al, byte [edi]
                    mov byte [ebx], al
                    sub edi, 1
                    add ebx, 1
                    jmp repeta1
                    
                final_repeta1:
                    mov byte [ebx], 0
                    
                push dword invers
                push dword format_afisare
                call [printf]
                add esp, 4*2
                
                mov edi, destinatie
                add esi, 1
                jmp repeta
        
    
        final_repeta:
            sub edi, 1
            mov ebx, invers
            repeta2:
                cmp edi, destinatie-1
                je final_repeta2
                mov al, byte [edi]
                mov byte [ebx], al
                sub edi, 1
                add ebx, 1
                jmp repeta2
        final_repeta2:
            mov byte [ebx], 0
            
            push dword invers
            push dword format_afisare
            call [printf]
            add esp, 4*2
                
    push dword 0
    call [exit]