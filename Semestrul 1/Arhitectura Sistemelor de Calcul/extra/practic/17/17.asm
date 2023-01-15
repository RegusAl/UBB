; Sir de la tastatura cu nr de maxim 5 cifre. sa se gaseasca max si min,sa se scrie in fisier, sa se inmulteasca si rezultatul sa se pastreze in mem.
bits 32

global start

extern exit, scanf, fopen, fclose, fprintf
import exit msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll

segment data use32 class=data
    nume_fisier db "fisier.txt", 0
    mod_fisier db "w", 0
    descriptor_fisier dd -1
    numar dd 0
    min dd 0
    max dd 0
    rezultat dq 0
    format_dec db "%d", 0
    ok db 0
    afisare db "Minim: %d, Maxim: %d. Rezultat: %d", 0
    
segment code use32 class=code
    start:
    
        ; citim numerele
        repeta:
        
            push dword numar
            push dword format_dec
            call [scanf]
            
            cmp dword [numar], 0
            je gata
            
            mov eax, [numar]
            
            cmp byte [ok], 0
            jne nu_primul
            
            mov dword [min], eax
            mov dword [max], eax
            mov byte [ok], 1
            
            nu_primul:
            
            cmp eax, [min]
            jg nu_minim
            mov [min], eax
            
            nu_minim:
            
            cmp eax, [max]
            jl nu_maxim
            mov [max], eax
            
            nu_maxim:
            
            mov dword [numar], 0
 
        jmp repeta

        gata:
        
        mov eax, [min]
        imul dword [max]
        
        mov dword [rezultat], eax
        mov dword [rezultat+4], edx

        ; deschidere fisier
        push dword mod_fisier
        push dword nume_fisier
        call [fopen]
        add esp, 2*4
        
        ; verificare fisier
        cmp eax, 0
        je final
        mov [descriptor_fisier], eax
        
        ; punem minimul si maximul in fisier
        push dword [rezultat+4]
        push dword [rezultat]
        push dword [max]
        push dword [min]
        push dword afisare
        push dword [descriptor_fisier]
        call [fprintf]
        add esp, 4*4
        
        final:
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 1*4
        
    push dword 0
    call [exit]