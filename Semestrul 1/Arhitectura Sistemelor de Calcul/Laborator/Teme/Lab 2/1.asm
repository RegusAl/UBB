; 4 - 5
bits 32

global start        

extern exit             
import exit msvcrt.dll   

segment data use32 class=data

segment code use32 class=code
    start:
    
        mov AL, 4   ; AL = 4
        sub AL, 5   ; AL = 4 - 5
        
        push    dword 0   
        call    [exit]       
