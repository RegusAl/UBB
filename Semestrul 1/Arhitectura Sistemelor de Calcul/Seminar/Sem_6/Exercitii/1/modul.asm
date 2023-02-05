bits 32

global addition

segment code use32 class=code
    addition:
    
        mov eax, [esp+4]
        add eax, [esp+8]
        
        ret