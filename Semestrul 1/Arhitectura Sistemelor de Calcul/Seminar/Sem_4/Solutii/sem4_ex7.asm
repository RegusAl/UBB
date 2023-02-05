bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    text db "ana are un cojoc"
    
; 7. Se dă un unui șir de octeți reprezentând un text
; (o succesiune de șiruri de caractere separate prin spații).
; Să se determine cuvintele din șirul p care sunt palindroame
; (de exemplu: ana, coc, capac, cojoc etc.).
segment code use32 class=code
    start:
        
    
        ; exit(0)
        push dword 0        ; push the parameter for exit onto the stack
        call [exit]         ; call exit to terminate the program
