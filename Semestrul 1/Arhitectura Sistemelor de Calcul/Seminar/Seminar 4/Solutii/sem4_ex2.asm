bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db 'a', 'b', 'c', 'd', 'e', 'f'

    
; 2. Se dă un șir de caractere s format din litere mici.
; Să se construiască un șir de caractere d care să conțină literele
; din șirul inițial transformate în majuscule, folosind instrucțiuni pe șiruri.
segment code use32 class=code
    start:
        
    
        ; exit(0)
        push dword 0        ; push the parameter for exit onto the stack
        call [exit]         ; call exit to terminate the program
