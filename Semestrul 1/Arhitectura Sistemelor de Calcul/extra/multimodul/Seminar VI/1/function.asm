bits 32

global addition

segment code use32 class=code
    addition:
        mov al, bl
        add al, bh
        ret