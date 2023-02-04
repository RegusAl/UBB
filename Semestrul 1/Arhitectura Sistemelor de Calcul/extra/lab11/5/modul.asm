bits 32

global operatie

segment code use32 class=code
    operatie:
    
        mov eax, dword [esp+8]   ; eax = a
        add eax, dword [esp+12]        ; ebx = a + b
        sub eax, dword [esp+16]

        mov dword [esp+4], eax
        
        ret 