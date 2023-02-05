;fiecare word din sir2 trebuie sa fie concatenarea octetului high din cuvantul high, si octetul high din cuvantul low
bits 32

global start

extern exit, printf, numarare_biti
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    sir dd 1234A678h, 12785634h, 1A4D3C26h, 12345678h
    len_sir equ ($-sir)/4
    sir_words times len_sir dw 0
    format_dec db "%d", 0
    
segment code use32 class=code
    start:
    
        mov edx, 0
        mov ecx, len_sir
        mov esi, sir
        mov edi, sir_words
        cld
        repeta:
            push ecx
            
            mov eax, 0
            lodsb
            lodsb   ; octetul high din cuvantul low
            mov bl, al
            lodsb
            lodsb   ; octetul high din cuvantul high
            mov ah, al
            mov al, bl      ; ax = cuvantul nou format
            
            stosw           ; punem pe ax in sir_words[edi]
            
            ; numarare_biti numara bitii de 1 din ax
            push eax
            call numarare_biti
            add esp, 4
            
            
            pop ecx
            
        loop repeta
        
        ; afisare suma ce este stocata in edx
        push dword edx
        push dword format_dec
        call [printf]
        add esp, 2*4
       
    push dword 0
    call [exit]