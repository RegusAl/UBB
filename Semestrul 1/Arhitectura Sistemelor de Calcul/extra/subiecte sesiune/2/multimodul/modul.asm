bits 32

global citire, suma

extern scanf, printf
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    numar dd  0
    format_dec db "%d", 0
    doi dd 2
    afisare db "%d ", 0
    zece dd 10

segment code use32 class=code
    citire:
    
        mov ecx, [esp+8]                        ; punem in ecx cate dublucuvinte vrem sa citim
        mov edi, [esp+4]
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
    
    ret
    
    suma:
    
        mov ecx, [esp+4]
        mov esi, [esp+8]
        mov edi, [esp+12]
        stocare_sume:
            push ecx
            
            mov ecx, 0           ; aici calculam suma
            
            lodsd               ; eax = sir[esi]
        
            ;mov [copie], eax    ; numar = copie a lui eax
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
                    
                impar:
                
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
        
    ret