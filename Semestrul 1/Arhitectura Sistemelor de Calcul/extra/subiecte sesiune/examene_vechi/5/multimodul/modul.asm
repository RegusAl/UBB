bits 32

global functie

extern sir_contor

segment code use32 class=code
    functie:
        
        mov esi, [esp+4]
        mov ecx, [esp+8]
        
        mov edx, '0'               ; numaram locatia
        ;mov ebx, 0               ; suma 
        repeta:
            
            lodsw
            lodsb       ; octetul inferior sin cuvantul superior (al)
            add dl, 1
            cmp al, 0
            jge pozitiv
            
            add bl, al
            
            mov [sir_contor+edi], dl
            inc(edi)
            
            pozitiv:
        
            lodsb
        
        loop repeta
        
        ret