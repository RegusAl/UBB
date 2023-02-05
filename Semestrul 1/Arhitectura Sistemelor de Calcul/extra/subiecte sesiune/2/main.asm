; Citim un n de la tastatura, apoi n dublucuvinte, Se cere sa se stocheze in memorie toate n dublucuvintele, apoi sa se formeze un nou sir de octeti, in care stocam suma cifrelor pare din fiecare dublucuvant citit
bits 32

global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    n dd 0                      ; numarul de dublucuvinte ce o sa se citeasca
    sir times 10 dd 0
    sir_suma resb 10
    zece dd 10
    format_dec db "%d", 0
    prompt_n db "n = ", 0
    numar dd 0
    doi dd 2
    afisare db "%d ", 0

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
        
        mov ecx, [n]                        ; punem in ecx cate dublucuvinte vrem sa citim
        mov edi, sir
        citire_dublucuvinte:                ; citim n dublucuvinte
            push ecx
                
                push numar
                push format_dec
                call [scanf]
                add esp, 2*4
                
                mov eax, [numar]
                stosd
        
            pop ecx
        loop citire_dublucuvinte
        
        ; punem in sirul de suma, suma cifrelor pare
        mov ecx, [n]
        mov esi, sir
        mov edi, sir_suma
        stocare_sume:
            push ecx
            
            mov ecx, 0           ; aici calculam suma
            
            lodsd               ; eax = sir[esi]
        
            mov [numar], eax    ; numar = copie a lui eax
            mov edx, 0
            
            ultima_cifra:
                mov edx, 0
                div dword [zece]    ; ultima cifra = edx
                push eax
                
                mov eax, edx        ; punem in eax restul impartirii
                mov ebx, eax        ; copie a lui eax in ebx
                mov edx, 0          ; edx:eax
                
                div dword [doi]     ; vedem  daca numarul este par sau impar
                cmp edx, 0
                jne impar           ; daca numarul este impar, sare la eticheta impar 
                
                    add ecx, ebx    ; adauga in ecx ultima cifra ce este para
                    
                impar
                
                pop eax
            
            cmp eax, 0              ; verificam daca dublucuvantul curent mai are cifre
            jne ultima_cifra
            
            mov eax, ecx            ; punem in eax suma cifrelor pare
            stosb                   ; sir_suma[edi] = al
            
            pushad                  ; punem pe stiva deoarece apelul functiei modifica anumiti registri
            
            ; afisam sirul de sume 
            push dword eax
            push dword afisare
            call [printf]
            add esp, 2*4
            
            popad                   ; luam de pe stiva
            
            pop ecx
        loop stocare_sume
        
    push dword 0
    call [exit]