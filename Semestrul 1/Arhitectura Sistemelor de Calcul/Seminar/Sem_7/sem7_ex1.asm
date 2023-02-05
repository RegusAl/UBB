bits 32
global start

extern exit, scanf, printf, strlen
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll
import strlen msvcrt.dll

segment data use32 class=data
	mesaj db "Dati o propozitie: ", 0
    
    len dd 0
    max_len equ 50
    invers times max_len db 0
    cuvant times max_len db 0
    format db "%s", 0
    
    format_afisare db "Cuvant: %s invers: %s", 13, 10, 0
    ; format_afisare db "Cuvant: %s lungime: %d", 13, 10, 0
    
; 30. Se citeste o propozitie de la tastatura.
; Sa se inverseze fiecare cuvant si sa se afiseze pe ecran.
segment code use32 class=code
    start:
        ; printf(mesaj)
        push dword mesaj
        call [printf]
        add esp, 1*4
    
        ; citim fiecare cuvant
    repeta:
        ; reinitializam sirurilor
        call init_strings
    
        ; scanf("%s", cuvant)
        push dword cuvant
        push dword format
        call [scanf]
        add esp, 2*4
        
        ; EAX = strlen(cuvant)
        push dword cuvant
        call [strlen]
        add esp, 1*4
        mov [len], eax
        
        ; reverse_word(len, cuvant, invers)
        push dword invers
        push dword cuvant
        push dword [len]
        call reverse_word
        add esp, 3*4
        
        push dword invers
        push dword cuvant
        push dword format_afisare
        call [printf]
        add esp, 3*4
        
        mov eax, [len]
        mov al, [cuvant+eax-1]
        cmp al, '.'
        jne repeta
        
    final:
        ; exit(0)
        push dword 0
        call [exit]
    
    ; initializeaza sirurile 'cuvant' si 'invers'
    init_strings:
        cld
        mov ecx, max_len
        mov edi, cuvant
        mov al, 0
        repe stosb
        
        cld
        mov ecx, max_len
        mov edi, invers
        mov al, 0
        repe stosb
        
        ret
        
    ; inverseaza un sir dat si-l stocheaza in alt sir
    reverse_word:
        mov ecx, [esp+4]    ; len
        mov esi, [esp+8]    ; cuvant
        mov edi, [esp+12]   ; invers
        add edi, ecx
        dec edi
    .repeta:
        cld
        lodsb
        std
        stosb
        loop .repeta
        
        cld
        ret
