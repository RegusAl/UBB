bits 32

global concatenare

segment code use32 class=code 
    concatenare:
    
        mov esi, [esp+4]
        mov edi, [esp+16]
        cld
        
        mov ecx, [esp+28]
        rep movsb 
        
        mov esi, [esp+8]
        mov ecx, [esp+24]
        rep movsb 
        
        mov esi, [esp+12]
        mov ecx, [esp+20]
        rep movsb 
        
        ret