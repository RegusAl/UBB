; Se dau doua siruri de caractere ordonate alfabetic s1 si s2. Sa se construiasca prin interclasare sirul ordonat s3 care sa contina toate elementele din s1 si s2. 
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s1 db 'a', 'd', 'e', 'l'
    len1 equ $-s1
    s2 db 'b', 'f', 'g', 'k'
    len2 equ $-s2
    s3 times len1+len2 db 0

segment code use32 class=code
    start:
        mov ecx, len1+len2
        jecxz final

        mov esi, s1
        mov ebx, s2
        mov edi, s3
        cld
        
        repeta:
            
            push ecx
            cmp esi, s1+len1
            je gata_s1
            cmp ebx, s2+len2
            je gata_s2
            
            mov al, [esi]
            mov ah, [ebx]
            cmp al, ah
            
            jb din_s1
               
               push esi
               mov esi, ebx
               movsb
               inc(ebx)
               pop esi
               jmp din_s2
            din_s1:
                movsb
            din_s2:
            
            pop ecx
            
            
        loop repeta
        jmp final
        
        gata_s1:
            mov esi, ebx                
            
        gata_s2:
            completare:                 
                movsb
            loop completare
        
    final:
    push dword 0
    call [exit]