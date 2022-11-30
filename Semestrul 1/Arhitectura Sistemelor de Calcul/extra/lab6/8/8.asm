;Se da un sir de dublucuvinte. 
;Sa se obtina sirul format din octetii inferiori ai cuvintelor superioare 
;din elementele sirului de dublucuvinte care sunt palindrom in scrierea in baza 10.
bits 32

global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data
    s dd 12345678h, 1A2C3C4Dh, 98FCDC76h
    len equ ($-s)/4 ; lungimea sirului s 
    d times len db 0
    zece db 10
    base db 16h


segment code use32 class=code
    start:
        mov ECX, len
        jecxz sfarsit
        cld ; DF=0
        mov ESI, s 
        mov EDI, d 
        
    repeta:
       
        lodsw ; AX = word-ul inferior
        lodsw ; AX = word-ul superior 
        
        mov AH, 0 
            
        push EAX
        mov BX, 0
        mov DX, 0
        construire:
            ;ogl=ogl*10+(nr%10)
            ;AX=nr 
            div byte [zece] 
            mov DL, AL 
            mov AL, BL 
            mov BL, AH 
            mov AH, 0 ; zerorizez= sterg restul 
            mul byte [zece] ;AX=AL*10=ogl*10
            add BX, AX ;BX=ogl*10+(nr%10)
    
            mov AX, DX 
            mov DX,0 
            cmp AX,DX 
            je verificare 
            jmp construire ; mai avem cifre in numar
        
        verificare:
            pop EAX ; nr initial a fost stocat in stiva 
            cmp AL,BL
            jne nuepalindrom ; nu e palindrom 
            stosb 
            
        nuepalindrom:           
        
    loop repeta
        
    sfarsit:

    push dword 0       
    call [exit]   
