bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db 4, 2, 7, 1, 9, 8, 3, 5, 6
    
    
; 6. Se dă un șir de octeți s.
; Să se ordoneze crescător elementele șirului s.
segment code use32 class=code
    start:
        
    
        ; exit(0)
        push dword 0        ; push the parameter for exit onto the stack
        call [exit]         ; call exit to terminate the program
