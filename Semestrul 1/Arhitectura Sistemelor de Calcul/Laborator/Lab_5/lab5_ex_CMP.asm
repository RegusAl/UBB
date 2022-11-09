bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
	a dd 24
    b dd 22

segment code use32 class=code
    start:
        mov eax, [a]
        cmp eax, [b]    ; scadere fictiva EAX - b
        ; if a < b
        jb mai_mic
        ; if b > a
        ja mai_mare
        
        
    mai_mic:
        ...
        jmp final
    mai_mare:
        ...
        
    final:
    
        mov eax, [a]
        cmp eax, [b]    ; scadere fictiva EAX - b
        ja mai_mare
        ...             ; a < b
        ...
        
        jmp final
        
    mai_mare:
        ...             ; a > b
        
    final:
    
    
    
        ; exit(0)
        push dword 0
        call [exit]
