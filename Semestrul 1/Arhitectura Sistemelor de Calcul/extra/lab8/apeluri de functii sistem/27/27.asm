; Se dă un sir de caractere (definit in segmentul de date). Să se citească de la tastatură un caracter, să se determine numărul de apariţii al acelui caracter în şirul dat şi să se afişeze acel caracter împreună cu numărul de apariţii al acestuia. 
bits 32
global start

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    mesaj_caracter db "caracterul = ", 0
    sir db "albert e cel mai tare", 0
    len_sir equ $-sir
    format_char db "%c", 0
    format_str db "%s", 0
    afisare db "Caracterul '%s' apare de %d ori", 0
    caracter times 1 db 0
    
    
segment code use32 class=code
    start:
    
        ; c = 
        push dword mesaj_caracter
        call [printf]
        add esp, 1*4
        
        ; citire caracterul c
        push dword caracter
        push dword format_char
        call [scanf]
        add esp, 2*4
        
        mov ecx, len_sir
        mov esi, 0
        mov al, [caracter]
        mov ebx, 0
        
        repeta:
                cmp al, [sir+esi]
                jne peste
                add ebx, 1
                peste: 
                inc esi
        loop repeta
        
        ; afisare
        push ebx
        push caracter
        push dword afisare
        call [printf]
        add esp, 3*4
     
    push dword 0
    call [exit]