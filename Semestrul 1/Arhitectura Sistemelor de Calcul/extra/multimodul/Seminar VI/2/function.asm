bits 32

global addition

extern a, b, x

segment code use32 class=code
    addition:
        
        mov al, [a]
        add al, [b]
        mov [x], al
        
        ret