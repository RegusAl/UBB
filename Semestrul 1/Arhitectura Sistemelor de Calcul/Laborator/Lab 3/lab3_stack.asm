bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data    

segment code use32 class=code
    start:
        mov dx, 1234h   ; cuvantul superior
        mov ax, 5678h   ; cuvantul inferior
        
        push dx         ; mai intai punem pe stiva cuvantul superior
        push ax         ; apoi punem pe stiva cuvantul inferior
        pop ebx         ; ebx = 12345678h (in ordinea corecta)
    
        ; exit(0)
        push dword 0    ; push the parameter for exit onto the stack
        call [exit]     ; call exit to terminate the program
