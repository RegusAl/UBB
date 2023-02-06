; Citim un n de la tastatura, apoi n dublucuvinte, Se cere sa se stocheze in memorie toate n dublucuvintele, apoi sa se formeze un nou sir de octeti, in care stocam suma cifrelor pare din fiecare dublucuvant citit
bits 32

global start

extern exit, printf, scanf, citire, suma
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    n dd 0                      ; numarul de dublucuvinte ce o sa se citeasca
    sir times 10 dd 0
    sir_suma resb 10
    format_dec db "%d", 0
    prompt_n db "n = ", 0
    
segment code use32 class=code
    start:
    
        ; citim n
        push dword prompt_n
        call [printf]
        add esp, 1*4
        
        push dword n
        push dword format_dec
        call [scanf]
        add esp, 2*4
        
        push dword [n]
        push dword sir
        call citire
        add esp, 2*4
        
        ; punem in sirul de suma, suma cifrelor pare
        push dword sir_suma
        push dword sir
        push dword [n]
        call suma
        add esp, 3*4
            
    push dword 0
    call [exit]