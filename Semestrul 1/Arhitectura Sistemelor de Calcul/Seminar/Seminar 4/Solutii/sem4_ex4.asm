bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s dw 1122h, 3344h, 5566h, 7788h
    
    
; Se dă un șir de cuvinte s.
; Să se construiască două șiruri de octeți:
; - b1 care are ca elemente partea superioară a cuvintelor din s
; - b2 care are ca elemente partea inferioară a cuvintelor din s
segment code use32 class=code
    start:
        
    
        ; exit(0)
        push dword 0        ; push the parameter for exit onto the stack
        call [exit]         ; call exit to terminate the program
