; Se da un sir de numere. Sa se afiseze valorile in baza 16 si in baza 2.
bits 32 

global start        

extern exit, hexprint, binprint               
import exit msvcrt.dll    
                                      
segment data use32 class=data
    numere dd 1,2,3,4,5,6,7,8,9,10
    len equ ($-numere)/4

segment code use32 class=code
    start:
        
        mov ecx, len
        jecxz .endprintloop
        
        mov ebx, numere
        .printloop:
            push ecx
            push ebx
            
            push dword [ebx]
            call binprint
            call hexprint
            add esp, 4
            
            pop ebx
            pop ecx
            add ebx, 4
        loop .printloop
        .endprintloop:
        
        push    dword 0      
        call    [exit]       

        
  