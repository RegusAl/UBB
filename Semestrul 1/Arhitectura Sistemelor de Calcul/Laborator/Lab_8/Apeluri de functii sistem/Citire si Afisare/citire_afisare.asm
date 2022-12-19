bits 32
global start

extern exit, printf, gets
import exit msvcrt.dll
import printf msvcrt.dll
import gets msvcrt.dll

segment data use32 class=data
    mesaj db "Dati un mesaj: ", 0
    format db "%s", 0
    s times 50 db 0
    afisare db "Mesajul este: %s", 0
    
segment code use32 class=code
    start:
            
        ; afisarea mesajului de inceput    
        push dword mesaj
        call [printf]
        add esp, 1*4
        
        ; citirea stringului
        push dword s
        call [gets]
        add esp, 1*4
        
        ; afisarea stringului
        push dword s
        push dword afisare
        call [printf]
        add esp, 2*4
        
    push dword 0 
    call [exit]