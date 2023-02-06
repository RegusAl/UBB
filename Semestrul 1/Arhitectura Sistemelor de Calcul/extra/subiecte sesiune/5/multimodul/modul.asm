bits 32

global numarare_biti, parte, afisare_sir_descrescator

extern sir_bytes, printf
import printf msvcrt.dll

segment data use32 class=data
    parte dd 0
    afisare_dec db "%d ", 0

segment code use32 class=code
    numarare_biti:
        
        mov edi, [esp+4]
        mov esi, 0
        cld
        repeta_bytes:
            push ecx 
            mov ecx, 8  ; fiecare byte are 8 biti
            mov bl, 0  ; contorul in care numaram bitii fiecarui byte
            mov al, 0
            mov al, [parte+esi]
            ; numaram bitii de 1 din octet
            repeta_biti:
                shl al, 1
                adc bl, 0
            loop repeta_biti
            add esi, 1
            mov al, bl
            stosb
            pop ecx
        loop repeta_bytes
        
        ret
        
    afisare_sir_descrescator:
    
        mov ecx, 8
        mov dl, 8      ; comparatorul
        afisare_sume:
            push ecx
            mov esi, 0 
            mov ecx, 4  ; sunt 4 valori
            afisare:
                mov eax, 0
                mov al, [sir_bytes+esi]
                cmp al, dl                      ; comparam 
                jne nu_egal
                
                    pushad
                    ; daca este egal cu contorul, afisam
                    push dword eax
                    push dword afisare_dec
                    call [printf]
                    add esp, 2*4
                    
                    popad
                
                nu_egal:
                
                inc(esi)
            
            loop afisare
            
            dec(dl)     ; decrementam contorul
        
            pop ecx
        loop afisare_sume
        
        ret