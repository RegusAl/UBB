bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    
    
; 3. Se dă un șir de octeți s.
; Să se construiască șirul de octeți d, care conține pe fiecare poziție
; numărul de biți care au valoarea 1 din octetul de pe poziția corespunzătoare din s.
; Exemplu:
; s: 5, 25, 55, 127
; elementele sirului s convertite in baza 2:
; 101, 11001, 10111, 1111111
; d: 2, 3, 5, 7
segment code use32 class=code
    start:
        
    
        ; exit(0)
        push dword 0        ; push the parameter for exit onto the stack
        call [exit]         ; call exit to terminate the program
