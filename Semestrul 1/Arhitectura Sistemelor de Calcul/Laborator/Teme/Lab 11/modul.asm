%ifndef modul.asm
%define modul.asm

dublare:
    mov eax,0
    mov eax,[esp+4]
    add eax,[esp+4]
    
    ret 4
    
%endif