bits 32

global factorial

segment code use32 class=code
    factorial:
    
        mov ecx, [esp+4]
        mov eax, 1
        repeta:
            mul ecx
        loop repeta
        
        ret