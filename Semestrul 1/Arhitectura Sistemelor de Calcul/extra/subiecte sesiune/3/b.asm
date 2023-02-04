bits 32

global rank_build

extern exit
import exit msvcrt.dll

extern rank

segment data use32 class=data
    max db 0
    sum db 0

segment code use32 class=code
    rank_build:
        ; [ESP+0] - Adrersa de revenire
        ; [ESP+4] - rank
        ; [ESP+8] - sirul de bytes
        ; [ESP+12] - sirul initial
        ; [ESP+16] - lungimea sirului
    
        mov ecx, [esp+16]
        mov esi, [esp+12]
        mov edi, [esp+8]
        mov ebx, 0
        mov edx, 0
        cld
        repeta:
            lodsd           ; eax = sir[esi]
            mov bl, 0
            push ecx
            mov byte [max], 0
            mov ecx, 4
            comparare_bytes:
                
                cmp al, [max]
                jbe peste
                mov [max], al
                mov bl, cl
                peste:
                shr eax, 8
            
            loop comparare_bytes
            
            mov al, [max]
            add byte [sum], al
            stosb 
            
            cmp bl, 4
            jne nu_4
            mov byte [rank+edx], '4' 
   
            nu_4:
            cmp bl, 3
            jne nu_3
            mov byte [rank+edx], '3' 
            
            nu_3:
            cmp bl, 2
            jne nu_2
            mov byte [rank+edx], '2' 
            
            nu_2:
            cmp bl, 1
            jne nu
            mov byte [rank+edx], '1'
               
            nu:
            
            inc(edx)
            
            pop ecx
        loop repeta
        
        mov eax, 0
        mov al, [sum]
        sub eax, 256
        
        ret
        
        push dword 0
        call [exit]