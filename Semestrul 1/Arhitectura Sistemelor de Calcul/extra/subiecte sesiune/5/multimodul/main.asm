;se da un sir de qwords si un n de la tastatura
;identifica al n+1 lea qword si stocheaza partea superioara/inferioara daca n e par/impar
;dupa descompui in bytes si vezi cati de 1 are fiecare byte in repr binara, afisezi sirul sortat descrescator
bits 32

global start, sir_bytes

extern exit, printf, scanf, numarare_biti, parte, afisare_sir_descrescator
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    ; sirul de qwords
    sir dq 123456789h, 0aabbccddeeffh, 1122334455667788h
    len_sir equ ($-sir)/8
    n dd 0
    format_n db "%d", 0
    prompt_n db "n = ", 0
    parte_superioara dd 0
    parte_inferioara dd 0
    doi dd 2
    ;parte dd 0
    sir_bytes times 4 db 0
       
segment code use32 class=code
    start:
    
        ; citire n
        push dword prompt_n
        call [printf]
        add esp, 1*4
    
        push dword n
        push dword format_n
        call [scanf]
        add esp, 2*4
        
        mov ebx, [n]
        
        mov edx, [sir+ebx*8+4]   ; partea superioara
        mov eax, [sir+ebx*8]     ; partea inferioara
        ; edx:eax - quadwordul 
        mov [parte_superioara], edx
        mov [parte_inferioara], eax
        
        mov edx, 0
        mov eax, [n]
        div dword [doi]             ; EDX = n % 2

        ;verificare n par / impar
        ; daca este impar, lum partea inferioara
        ; daca este par, lum partea superioara
        cmp edx, 0
        je par
        mov eax, [parte_inferioara]
        mov dword [parte], eax

        jmp peste
        
        par:
        mov eax, [parte_superioara]
        mov dword [parte], eax
        
        peste:
        ; partea ce trebuie luata este in [parte]
        
        mov ecx, 4      ; deoarece avem 4 octeti in [parte] = 32 biti
        
        ; punem in sir_bytes suma bitilor 1 din octet
        push dword sir_bytes
        call numarare_biti
        add esp, 4
        
        ; afisare sir descrescator
        ; stim ca numarul maxim de biti de 1 intr-un octet este 8
        ;luam si comparam fiecare element si afisam daca este egal cu un contor pe care o sa-l tot scadem
        ; METODA CIOBANEASCA :D
        call afisare_sir_descrescator
        
    
    push dword 0
    call [exit]