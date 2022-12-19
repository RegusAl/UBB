bits 32
global start

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    mesaj db "Hello World!"

segment code use32 class=code
    start:
        
        push dword mesaj
        call [printf]
        add esp, 1*4
    
    push dword 0
    call [exit]