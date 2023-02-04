bits 32

global hexprint
global binprint

extern printf
import printf msvcrt.dll

segment data use32 class=data
    hexformat db " %x",10,0
    binformat db "%d", 0

segment code use32 class=code
    hexprint:
        
        push dword [esp+4]
        push dword hexformat
        call [printf]
        add esp, 4*2
        
        ret
        
    binprint:
    
        mov eax, [esp+4]
        
        mov ecx, 32
        .bitloop:
            clc
            shl eax, 1
            push eax
            push ecx
            jnc .zero
            ;one:
                call .print1
                jmp .endiff
            .zero:
                push dword 0
                push dword binformat
                call [printf]
                add esp, 2*4
            .endiff:
            pop ecx
            pop eax
                
        
        loop .bitloop
 
        ret
        
    .print1:
                push dword 1
                push dword binformat
                call [printf]
                add esp, 2*4
                ret
    